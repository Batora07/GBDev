#include <gb.h>

#include "bgtile1.c"
#include "bgmap3.c"

#include "girl.c"


// �֐��v���g�^�C�v�錾
void  SET_MOVE_SPRITE();
void  INIT();
void  PATTERN_CHANGE();
UBYTE AHEAD_KABE();
UBYTE LEFT_KABE();
void  MOVE_HAMUMI();


UBYTE gx, gy, gd, gp;

UBYTE hamumi_tile[4][2][4] =
{
	0, 1, 2, 3,       /* direct North */
	4, 5, 6, 7,

	8, 9, 10, 11,     /* direct East */
	12, 13, 14, 15,

	16, 17, 18, 19,   /* direct South */
	20, 21, 22, 23,

	24, 25, 26, 27,   /* direct West */
	28, 29, 30, 31
};

void SET_MOVE_SPRITE()
{
	set_sprite_tile( 0, hamumi_tile[gd][gp][0] );
	set_sprite_tile( 1, hamumi_tile[gd][gp][1] );
	set_sprite_tile( 2, hamumi_tile[gd][gp][2] );
	set_sprite_tile( 3, hamumi_tile[gd][gp][3] );

	move_sprite( 0, gx * 8 + 8, gy * 8 + 16 );
	move_sprite( 1, gx * 8 + 8, gy * 8 + 24 );
	move_sprite( 2, gx * 8 + 16, gy * 8 + 16 );
	move_sprite( 3, gx * 8 + 16, gy * 8 + 24 );
}

void INIT()
{
	UBYTE i;

	disable_interrupts();
	HIDE_BKG;
	HIDE_SPRITES;
	HIDE_WIN;
	DISPLAY_OFF;

	set_bkg_data( 0, 5, bgtile1 );
	set_bkg_tiles( 0, 0, bgmap3Width, bgmap3Height, bgmap3 );

	set_sprite_data( 0, 32, girl );
	SPRITES_8x8;

	gx = gy = 1;
	gd = 2;
	gp = 1;

	SET_MOVE_SPRITE();

	for( i = 0; i < 4; i++ ){
		set_sprite_prop( i, 0 );
	}

	SHOW_BKG;
	SHOW_SPRITES;
	DISPLAY_ON;
	enable_interrupts();
}

void PATTERN_CHANGE()
{
	gp = ( gp == 0 ) ? 1 : 0 ;
}

UBYTE AHEAD_KABE()   // �O���ɕǂ����邩�ǂ����@��������1���@�Ȃ����0��Ԃ�
{
	UWORD C1, C2;
	switch(gd){
		case 0:
			C1 = (UWORD)(gy - 1) * bgmap3Width + gx;
			C2 = C1 + 1;
			break;
		case 1:
			C1 = (UWORD)gy * bgmap3Width + (gx + 2);
			C2 = C1 + bgmap3Width;
			break;
		case 2:
			C1 = (UWORD)(gy + 2) * bgmap3Width + gx;
			C2 = C1 + 1;
			break;
		case 3:
			C1 = (UWORD)gy * bgmap3Width + (gx - 1);
			C2 = C1 + bgmap3Width;
			break;
	}

	if( *(bgmap3 + C1) != 0x00 || *(bgmap3 + C2) != 0x00 ) return 1;

	return 0;
}

UBYTE LEFT_KABE()   // ���ɕǂ����邩�ǂ����@��������1���@�Ȃ����0��Ԃ�
{
	UWORD C3, C4;

	switch(gd){
		case 0:
			C3 = (UWORD)gy * bgmap3Width + (gx - 1);
			C4 = C3 + bgmap3Width;
			break;
		case 1:
			C3 = (UWORD)(gy - 1) * bgmap3Width + gx;
			C4 = C3 + 1;
			break;
		case 2:
			C3 = (UWORD)gy * bgmap3Width + (gx + 2);
			C4 = C3 + bgmap3Width;
			break;
		case 3:
			C3 = (UWORD)(gy + 2) * bgmap3Width + gx;
			C4 = C3 + 1;
			break;
	}

	if(( *(bgmap3 + C3) != 0x00 ) || ( *(bgmap3 + C4) != 0x00 )) return 1;

	return 0;
}

void MOVE_HAMUMI()
{
	if( LEFT_KABE() == 0 ){  // ��ԍŏ��Ɍ���͍̂����ǂ��ʘH���ǂ����H�@�����ʘH��������
		switch(gd){
			case 0:
				gd = 3;  // ���Ɍ�����ς���
				gx--;    // ����i��
				break;
			case 1:
				gd = 0;
				gy--;
				break;
			case 2:
				gd = 1;
				gx++;
				break;
			case 3:
				gd = 2;
				gy++;
				break;
		}
	}else if(AHEAD_KABE() == 0 ){  // ���Ɍ���̂́@�i�s�����̑O�����ʘH���ǂ����H�@�ʘH��������
		switch(gd){
			case 0:
				gy--;  // �i�s�����ɐi��
				break;
			case 1:
				gx++;
				break;
			case 2:
				gy++;
				break;
			case 3:
				gx--;
				break;
		}
	}else{                         // �����O���ǁi�ʘH����Ȃ��j��������
		switch(gd){
			case 0:
				gd = 1;  // �������E�ɕς���
				break;
			case 1:
				gd = 2;
				break;
			case 2:
				gd = 3;
				break;
			case 3:
				gd = 0;
				break;
		}
	
	}

	PATTERN_CHANGE();
	SET_MOVE_SPRITE();
}

void main()
{
	INIT();

	for(;;){

		MOVE_HAMUMI();

		if( gx == 17 && gy == 15) break;  // �I������@�n���݂���ԉE���ɓ��������烋�[�v�𔲂���

		delay(300);
	}

}

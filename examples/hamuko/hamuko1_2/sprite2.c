#include <gb.h>

#include "bgtile1.c"
#include "bgmap1.c"

#include "girl.c"

UBYTE gx, gy, gd, gp;  // x���W,�@y���W,�@����,�@�p�^�[��

UBYTE hamumi_tile[4][2][4] =  // ���p�S�@�ɂ��Q�p�^�[���̊G���@�^�C���S���ŏo���Ă���
{
	0, 1, 2, 3,        /* direct North */
	4, 5, 6, 7,

	8, 9, 10, 11,      /* direct East */
	12, 13, 14, 15,

	16, 17, 18, 19,    /* direct South */
	20, 21, 22, 23,

	24, 25, 26, 27,    /* direct West */
	28, 29, 30, 31
};

void SET_MOVE_SPRITE()  // �X�v���C�g�^�C���̃Z�b�g�ƕ\���ʒu
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
	set_bkg_tiles( 0, 0, bgmap1Width, bgmap1Height, bgmap1 );

	set_sprite_data( 0, 32, girl );
	SPRITES_8x8;

	gx = gy = 9;   // �X�v���C�g�̍��W�̏�����
	gd = 0;   // �X�v���C�g�̕����̏�����
	gp = 0;   // �X�v���C�g�̃p�^�[���̏�����

	SET_MOVE_SPRITE();

	for( i = 0; i < 4; i++ ){          // �X�v���C�g4���̕\����W���ɐݒ�
		set_sprite_prop( i, 0 );
	}

	SHOW_BKG;
	SHOW_SPRITES;
	DISPLAY_ON;
	enable_interrupts();
}

void main()
{

	INIT();

}

#include <gb.h>
#include <stdio.h>
#include <rand.h>    // �������g���ׂ̃w�b�_�[�t�@�C��

#include "hamumoji.c"   // �n���q�����̃^�C���f�[�^

/*--------------------------------------------------------*/
void INIT();
void RANSUU_INIT();
void DISP_MESSAGE();

/*--------------------------------------------------------*/
fixed seed;  // �����̎�
UBYTE r;     // ����

/*--------------------------------------------------------*/
void INIT()  // ��ʂ̏�����
{
	printf( " " );

	disable_interrupts();
	HIDE_BKG;
	HIDE_SPRITES;
	HIDE_WIN;
	DISPLAY_OFF;

	set_bkg_data( 160, 65, hamumoji );    // �n���q�����Ɏg���^�C���f�[�^�@160�ԁ`�@65���@hamumoji�i�ō�����^�C���j���Z�b�g����
	
	SHOW_BKG; 
	DISPLAY_ON;
	enable_interrupts();
}

/*--------------------------------------------------------*/
void RANSUU_INIT() //�����̏������@���̂�����SDK��example�t�H���_�̒��ɂ���܂�
{
	UBYTE x, y;
	x = y = 1;

	gotoxy( x, y ) ;
	printf("�Ѻ� ���޳�") ;
	gotoxy( x, y + 2 );
	printf("�ݽ��֯� ����Ͻ");
	gotoxy( x + 2, y + 5 );
	printf("[A]���ݦ ����");
	gotoxy( x, y + 7 );
	printf("-----------------");

	waitpad(J_A);
	seed.b.l = DIV_REG;
	waitpadup();
	seed.b.h = DIV_REG;

	initarand(seed.w);   // �����̏�����

}

/*--------------------------------------------------------*/
void DISP_MESSAGE()   // r�̂Ƃ�l�ɂ���ĕ\�����b�Z�[�W��ς��Ă݂�
{
	UBYTE x, y;
	x = 3, y = 10;

	gotoxy( x, y );
	printf("r = %u", r );
	gotoxy( x, y + 2 );
	    switch(r){
		case 0:
			printf("�Ѻ� Ư���δ���");
			break;
		case 1:
			printf("�Ѻ� Ц�ӯò�  ");
			break;
		case 2:
			printf("�Ѻ� �ѯüϯ���");
			break;
		case 3:
			printf("�Ѻ� Ҧ�ϼ�!   ");
			break;
		case 4:
			printf("�Ѻ� ���޶�ϯ� ");
			break;
	    }

}

/*--------------------------------------------------------*/
void main()
{
	UBYTE pad;

	INIT();
	RANSUU_INIT();

	for(;;){
		pad = joypad();

		r = rand() % 5;   // r �̂Ƃ�l�́@0����4

		if( pad & J_A ){
			DISP_MESSAGE();
			waitpadup();
		}
	}

}


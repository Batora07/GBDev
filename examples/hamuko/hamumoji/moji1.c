#include <gb.h>
#include <stdio.h>

#include "hamumoji.c"    // �n���q�����̃^�C���f�[�^


void DISP_MOJI()
{
	gotoxy( 2, 2 );
	printf( "Hello World!" );

	gotoxy( 2, 4 );
	printf( "�۰ ܰ��ޤ" ); // �n���q�����͔��p�J�^�J�i�ŏ���
				// ����͎g�p�p�x�����Ȃ��̂Ł@�!��ƕ\�������悤�ɂ��Ă��܂�
}

void INIT()  // ��ʂ̏�����
{
	printf( " " );     // ��ʂ̏������̑O�Ɂ@����1�s���Ȃ��Ɓ@�n���q�����������������܂�

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

void main()
{
	INIT();
	DISP_MOJI();

}


#include <gb.h>
#include <stdio.h>

#include "hamumoji.c"   // �n���q�����̃^�C���f�[�^

#define MOJI_MAX 15
// ���̈�ԍŌ��NULL������̂Ł@���ۂɎg����̂�14����

void DISP_MOJI()
{
	UBYTE x, y, i;

	unsigned char first[MOJI_MAX] = "�ѺӼ�� ���̳�";  // �n���q�����͔��p�J�^�J�i�ŏ���
	unsigned char second[MOJI_MAX] = "¶��Ķ� �޷Ͻ�"; // 14�����ȓ��ɂ���
	unsigned char third[MOJI_MAX] = "�׶�Ŷ� ¶�ٯ�";
	unsigned char fourth[MOJI_MAX] = "��� �ڼ���Ͻ�";

	x = y = 2;

		for( i = 0; i < MOJI_MAX; i++ ){     // �ꕶ�����o�Ă���悤�ɂ��邽�߂̃��[�v

			set_bkg_tiles( x + i, y, 1, 1, &first[i] );
			delay(100);      // �����̒���
		}

		for( i = 0; i < MOJI_MAX; i++ ){

			set_bkg_tiles( x + i, y + 2, 1, 1, &second[i] );
			delay(100);
		}

		set_bkg_tiles( x, y + 6, MOJI_MAX, 1, third );
		set_bkg_tiles( x + 2, y + 8, MOJI_MAX, 1, fourth );

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


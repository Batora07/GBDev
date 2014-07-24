#include <gb/gb.h>

#include "bgtile1.c"  // �w�i�̃^�C���f�[�^
#include "bgmap1.c"   // �w�i�̃}�b�v�f�[�^


void INIT()  // ��ʂ̏�����
{
	disable_interrupts();
	HIDE_BKG;
	HIDE_SPRITES;
	HIDE_WIN;
	DISPLAY_OFF;

	set_bkg_data( 0, 5, bgtile1 );    // �w�i�Ɏg���^�C���f�[�^0�ԁ`�@5���@bgtile1�i�ō�����^�C���j���Z�b�g����
	set_bkg_tiles( 0, 0, bgmap1Width, bgmap1Height, bgmap1 );�@// �}�b�v�f�[�^bgmap1��w�i�ɃZ�b�g����
           // bgmap1Width, bgmap1Height �́@bgmap1.c �ɒ�`����Ă���
           // bgmap1Width 20  bgmap1Height 18

	SHOW_BKG;       // �w�i��\������
	DISPLAY_ON;
	enable_interrupts();
}

void main()
{

	INIT();

}

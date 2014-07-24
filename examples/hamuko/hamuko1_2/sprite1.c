#include <gb.h>

#include "bgtile1.c"
#include "bgmap1.c"

#include "girl.c"  // �X�v���C�g�Ɏg���^�C���f�[�^

void ABOUT_SPRITE()  // �X�v���C�g�ɂ��Ă̊�{�ݒ�
{
	UBYTE gx, gy;   // �X�v���C�g�L�����N�^�i���̎q�j�̍��W

	set_sprite_data( 0, 32, girl );  // �X�v���C�g�Ɏg���^�C���f�[�^0�ԁ`�@32���@girl�i�ō�����^�C���j���Z�b�g����
	SPRITES_8x8;

	gx = gy = 9;       // �X�v���C�g�̕\���ʒu���W�̏�����

        // ���̎q��l��\������̂ɃX�v���C�g�^�C����4���g���Ă��܂�

	set_sprite_tile( 0, 16 );  // �X�v���C�g�^�C���ԍ�0�Ԃɂ́@�^�C���f�[�^girl��16�Ԃ��Z�b�g���܂�
	set_sprite_tile( 1, 17 );
	set_sprite_tile( 2, 18 );
	set_sprite_tile( 3, 19 );

	move_sprite( 0, gx * 8 + 8, gy * 8 + 16 );  // �X�v���C�g�^�C���ԍ�0�Ԃ̕\���ʒu�́@(gx * 8 + 8, gy * 8 + 16) 
	move_sprite( 1, gx * 8 + 8, gy * 8 + 24 );
	move_sprite( 2, gx * 8 + 16, gy * 8 + 16 );
	move_sprite( 3, gx * 8 + 16, gy * 8 + 24 );

	set_sprite_prop( 0, 0 );  // �X�v���C�g�̕\�����@��W���ɐݒ肵�܂�
	set_sprite_prop( 1, 0 );
	set_sprite_prop( 2, 0 );
	set_sprite_prop( 3, 0 );

}

void INIT()
{
	disable_interrupts();
	HIDE_BKG;
	HIDE_SPRITES;
	HIDE_WIN;
	DISPLAY_OFF;

	set_bkg_data( 0, 5, bgtile1 );    
	set_bkg_tiles( 0, 0, bgmap1Width, bgmap1Height, bgmap1 );

	ABOUT_SPRITE();   // �X�v���C�g�ɂ��Ă̊�{�ݒ�

	SHOW_BKG;
	SHOW_SPRITES;     // �X�v���C�g��\������
	DISPLAY_ON;
	enable_interrupts();
}

void main()
{

	INIT();

}

#include <gb.h>
#include <stdio.h>
#include <rand.h>    // �������g���ׂ̃w�b�_�[�t�@�C��


/*--------------------------------------------------------*/
void RANSUU_INIT()  //�����̏������@���̂�����SDK��example�t�H���_�̒��ɂ���܂�
{
  fixed seed;  // �����̎�

	printf(" ");
	gotoxy( 2, 5 ) ;
	printf("Please push [A]") ;  // �uA�{�^���������Ă��������v
	gotoxy( 2, 8 );
	printf("- for get seed -");  // �u�����̎�𓾂�ׂɁv
	waitpad(J_A);
	seed.b.l = DIV_REG;
	waitpadup();
	seed.b.h = DIV_REG;

	initarand(seed.w);   // �����̏�����

}

/*--------------------------------------------------------*/
void main()
{
	UBYTE i, r1, r2;

	RANSUU_INIT();
	
	cls();

	// printf(" ");  RANSUU_INIT()�Ƃ����֐��̒���printf�����Ɏg���Ă���̂Ł@�����͂Ȃ��Ă����v

	for( i = 0; i < 10; i++ ){

		r1 = rand();   // r1�́@�Ă񂾗������̂���
		r2 = r1 % 10;  // �Ă񂾗�����10�Ŋ������]��Ȃ̂Ł@r2�̂Ƃ�l��0����9
		
		gotoxy( 1, i );
		printf( "%u", r1 );

		gotoxy( 10, i );
		printf( "%u", r2 );

	}

}


#include <gb.h>
#include <stdio.h>
#include <rand.h>    // �������g���ׂ̃w�b�_�[�t�@�C��


void main()
{
	UBYTE i, r1, r2;
	
	printf(" ");

	for( i = 0; i < 10; i++ ){

		r1 = rand();   // r1�́@�Ă񂾗������̂���
		r2 = r1 % 10;  // �Ă񂾗�����10�Ŋ������]��Ȃ̂Ł@r2�̂Ƃ�l��0����9
		
		gotoxy( 1, i );
		printf( "%u", r1 );

		gotoxy( 10, i );
		printf( "%u", r2 );

	}

}


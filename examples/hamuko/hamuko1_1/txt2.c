#include <gb.h>
#include <stdio.h>


void main()
{

	UBYTE y;

	printf( " " );

	for( y = 19; y > 3; y-- ){    

		cls();                   // ��񂲂Ƃɉ�ʂ��N���A

		gotoxy( 4, y );
		printf( "Presented by" );

		gotoxy( 7, y + 2 );
		printf( "Hamuko" );

		gotoxy( 5, y + 6 );
		printf( "Welcome to" );

		gotoxy( 2, y + 8 );
		printf( "** DEKIRUKANA **" );

		delay( 300 );              // ��������̂ő��x����

	}


}

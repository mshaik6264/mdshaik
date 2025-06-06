#include <stdio.h>
char key = 0xA5;  //secret key

// Encryption the data using a same key
void Encrypt_data(char *data)
{
	printf("Encryption:\n");
	for(int i=0;data[i]!='\0';i++)
	{
		data[i] ^= key;
		printf("%02x ",data[i]);
		printf("%c ",data[i]);
	}
	printf("\n");
}
// Decryption the data using a same key
void Decrypt_data(char *data)
{
	printf("Decryption:\n");
	for(int i=0;data[i]!='\0';i++)
	{
		data[i] ^= key;
		printf("%02x ",data[i]);
		printf("%c ",data[i]);
	}
	printf("\n");
}
void data_print_hex(char *data)
{
	printf("Orginal data in Hex:\n");
	for(int i=0;data[i]!='\0';i++)
	{
		printf("%02x ",data[i]);
		printf("%c ",data[i]);
	}
	printf("\n");
}
int main()
{
	char str[]="MohammadShaik";
	data_print_hex(str);
	Encrypt_data(str);
	Decrypt_data(str);
}

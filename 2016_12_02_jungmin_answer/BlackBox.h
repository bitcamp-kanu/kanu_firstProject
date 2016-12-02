#pragma once
//암호화 복호화.


//Reverse 를 사용하여 파일을 Encode,Decode 한다.
int ReverseEncodeDecode(char* srcPath,char* tarPath);
//Exclusive 를 사용하여 파일을 Encode,Decode 한다.
int ExclusiveEncodeDecode(char* srcPath,char* tarPath,char key);



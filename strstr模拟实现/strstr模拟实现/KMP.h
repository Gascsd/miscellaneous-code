#pragma once

#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>


void GetNext(int* next, const char* sub);
int KMP(const char* str, const char* sub, int pos);

#pragma once
#ifndef _MYLIB_H_
#define _MYLIB_H_
//��������� pragma ����� �� �������������� ���������� �������������
//������� �������� ����������� ifndef � define
namespace mylib {
	void arrayInit(float *arr, const size_t size);
	void arrayShow(float* arr, const size_t size);
	void countPositiveNegative(float* arr, const size_t size);
}
#endif // _MYLIB_H_
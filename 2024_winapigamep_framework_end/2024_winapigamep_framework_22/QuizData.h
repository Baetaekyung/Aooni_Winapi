#pragma once

enum class QuizEnum
{
	MOTIVE,
	MATH,
	NONSENSE,
	NONSENSE2,
	NONSENSE3
};

struct QuizDataSet
{
	wstring question;
	wstring answer;
	wstring errorMessage;
};

class QuizData
{
public:
	QuizData();
	~QuizData();
public:
	std::unordered_map<QuizEnum, QuizDataSet> quizs;
private:
	QuizDataSet quiz1 = {
		L"�츮�� ��Ƽ�� �� ������? (����� ���Ͻÿ�)",
		L"aooni", 
		L"���� aooni�Դϴ�.." 
	};
	QuizDataSet quiz2 = {
		L"������ ��ȣ�� �ۼ��Ͻÿ�..",
		L"lim",
		L"������ lim�Դϴ� ����"
	};
	QuizDataSet quiz3 = {
		L"���󿡼� ���� ���� ���ڴ�?",
		L"190000",
		L"������.."
	};
	QuizDataSet quiz4 = {
		L"����⸦ ������ ���� �ÿ������� ������? (������ ����)",
		L"horse",
		L"Halls(���� �ÿ������� ����)�̱� ����..(������ �Ǽ�)"
	};
	QuizDataSet quiz5 = {
		L"�Ƹ�尡 ������?!?!?",
		L"diamond",
		L"���̾Ƹ�� �Դϴ� ����"
	};
};
#pragma once

enum class QuizEnum
{
	MOTIVE,
	MATH,
	NONSENSE
};

struct QuizDataSet
{
	wstring question;
	wstring answer;
	wstring errorMessage;
};

class QuizData
{
	std::unordered_map<QuizEnum, QuizDataSet> quizs = 
	{ 
		{QuizEnum::MOTIVE, quiz1}, 
		{QuizEnum::MATH, quiz2},
		{QuizEnum::NONSENSE, quiz3},

	};

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
};


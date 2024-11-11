#include "pch.h"
#include "Aooni.h"
#include "Collider.h"

Aooni::Aooni()
{
	this->AddComponent<Collider>();
}

Aooni::~Aooni()
{
}

void Aooni::Update()
{
}

void Aooni::Render(HDC _hdc)
{
}

void Aooni::CreateProjectile()
{
}

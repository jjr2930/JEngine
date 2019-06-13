#include "JRenderer_DX12.h"
#include "../../BuiltInClass/JMesh.h"

using namespace JSample;

JMesh * JSample::JRenderer::GetMesh()
{
	return _mesh;
}

void JSample::JRenderer::SetMesh(JMesh* mesh)
{
	_mesh = mesh;
}

JList<JVector3>* JSample::JRenderer::GetVertices()
{
	return this->_mesh->GetVertices();
}

void JSample::JRenderer::SetVertices( JList<JVector3>* vertices)
{
	_mesh->SetVertices(vertices);
}

JList<uint16_t>* JSample::JRenderer::GetIndices()
{
	return _mesh->GetIndices();
}

void JSample::JRenderer::SetIndices( JList<uint16_t>* indices)
{
	_mesh->SetIndices(indices);
}

JList<JVector3>* JSample::JRenderer::GetNormals()
{
	return _mesh->GetNormals();
}

void JSample::JRenderer::SetNormals( JList<JVector3>* normals)
{
	_mesh->SetNormals(normals);
}

void JSample::JRenderer::SetShader( JShader* shader)
{
	_shader = shader;
}

JShader * JSample::JRenderer::GetShader()
{
	return _shader;
}
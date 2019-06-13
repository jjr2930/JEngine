#include "JMesh.h"

using namespace JSample;

JSample::JMesh::JMesh() {}


JSample::JMesh::JMesh(JList<JVector3>* vertices, JList<uint16_t>* indices, JList<JVector3>* normals)
{
	_vertices = vertices;
	_indices = indices;
	_normals = normals;
}

JList<JVector3>* JSample::JMesh::GetVertices()
{
	return _vertices;
}

JList<uint16_t>* JSample::JMesh::GetIndices() 
{
	return _indices;
}

JList<JVector3>* JSample::JMesh::GetNormals()
{
	return _normals;
}

void JSample::JMesh::SetVertices( JList<JVector3>* vertices)
{
	_vertices = vertices;
}

void JSample::JMesh::SetIndices( JList<uint16_t>* indices)
{
	_indices = indices;
}

void JSample::JMesh::SetNormals( JList<JVector3>* normals)
{
	_normals = normals;
}

JMesh & JSample::JMesh::operator=(const JMesh & rhs)
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	this->m_id = rhs.m_id;
	this->_vertices = rhs._vertices;
	this->_indices = rhs._indices;
	this->_normals = rhs._normals;
	return *this;
}
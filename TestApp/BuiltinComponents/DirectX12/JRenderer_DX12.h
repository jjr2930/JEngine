#if __DIRECTX_12__
#pragma once
#include "../JComponent.h"
#include "../../DataStructure/JList.h"
#include "../../BuiltInDataType/JVector3.h"

using namespace JSample::DataStructure;
using namespace JSample::JDataType;

namespace JSample
{
	class JShader;
	class JMesh;

	class JRenderer : public JComponent
	{
	private:
		JShader* _shader = nullptr;
		JMesh* _mesh = nullptr;

	public:
		JMesh* GetMesh();
		void SetMesh(JMesh* mesh);

		JList<JVector3>* GetVertices();
		void SetVertices(JList<JVector3>* vertices);

		JList<uint16_t>* GetIndices();
		void SetIndices(JList<uint16_t>* indices);

		JList<JVector3>* GetNormals();
		void SetNormals(JList<JVector3>* normals);

		void SetShader(JShader* shader);
		JShader* GetShader();

		void SetProperty(std::wstring propertyName, int value) {}
		void SetProperty(std::wstring propertyName, float value) {}
	};
}
#endif
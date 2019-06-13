#if __DIRECTX_12__
#pragma once
#include "../JObject.h"
#include "../BuiltInDataType/JVector3.h"
#include "../DataStructure/JList.h"

using namespace JSample::DataStructure;
using namespace JSample::JDataType;

namespace JSample {
	class JMesh : public JObject
	{
	private:
		JList<JVector3>* _vertices = nullptr;
		JList<uint16_t>* _indices = nullptr;
		JList<JVector3>* _normals = nullptr;

	public :
		JMesh();
		JMesh(	JList<JVector3>* vertices, 
				JList<uint16_t>* indices, 
				JList<JVector3>* normals);


		JList<JVector3>* GetVertices() ;
		JList<uint16_t>* GetIndices() ;
		JList<JVector3>* GetNormals();

		void SetVertices(JList<JVector3>* vertices);
		void SetIndices(JList<uint16_t>* indices);
		void SetNormals(JList<JVector3>* normals);

		JMesh& operator= (const JMesh& rhs);
	};
}
#endif

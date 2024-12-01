#include "DPhysicsManager.h"
#include "DCollision.h"
#include "DEngine.h"

DList<DCollisionData*> DPhysicsManager::objects = DList<DCollisionData*>();

DPhysicsManager::DPhysicsManager()
{
    gravity = DGravity(700); // �ӽ�
}

void DPhysicsManager::AddObject(DCollisionData* object) {    
    objects.AddNext(object); // ��ü �߰�
}

void DPhysicsManager::UpdateObjects(float deltaTime) {
    for (int i = 0; i < objects.GetSize(); i++) {
        DCollisionData* obj = objects.GetValue();

        gravity.ApplyGravity(*obj, deltaTime); // �߷� ����
        obj->UpdatePosition(deltaTime); // ��ġ ������Ʈ
        objects.Move();
    }
}




void DPhysicsManager::ResolveCollisions() {
    for (int i = 0; i < objects.GetSize(); i++) {
        DCollisionData* objA = objects.GetValue();
        //objects.Move();  // ���� ��ü�� �̵�

        for (int j = 1; j < objects.GetSize(); j++) {
            objects.Move();  // ���� ��ü�� �̵�
            DCollisionData* objB = objects.GetValue();
            DCollisionDetector detector(objA, objB);
            if (detector.DetectCollision()) {
                objA->OnCollision(objB);


                DEngine::LogMessageBox("�浹");
                // �浹 ó��
                //detector.ResolveCollision(objA, objB);

            }
            
        }
        //objects.Move();  // ���� ��ü�� �̵�
        
    }
}

    


void DPhysicsManager::SetParent(DCollisionData* parent, DCollisionData* child) {
        child->SetParent(parent); 
        parent->AddChild(child);
}

void DPhysicsManager::RemoveParent(DCollisionData* child) {
    DCollisionData* parent = child->GetParent();
    if (parent) {
        parent->RemoveChild(child); 
        child->SetParent(nullptr);  
    }
}
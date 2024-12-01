#include "DPhysicsManager.h"
#include "DCollision.h"
#include "DEngine.h"

DList<DCollisionData*> DPhysicsManager::objects = DList<DCollisionData*>();

DPhysicsManager::DPhysicsManager()
{
    gravity = DGravity(700); // �ӽ�
    hMutex = CreateMutex(NULL, false, NULL);
}

DPhysicsManager::~DPhysicsManager()
{
    CloseHandle(hMutex);
}

void DPhysicsManager::AddObject(DCollisionData* object) {    
    //DWORD result = WaitForSingleObject(hMutex, INFINITE);  // ���ؽ� ���
    objects.AddNext(object); // ��ü �߰�
    //ReleaseMutex(hMutex);  // ���ؽ� ����
}

void DPhysicsManager::UpdateObjects(float deltaTime) {
    DWORD result = WaitForSingleObject(hMutex, INFINITE);  // ���ؽ� ���
    for (int i = 0; i < objects.GetSize(); i++) {
        DCollisionData* obj = objects.GetValue();

        gravity.ApplyGravity(*obj, deltaTime); // �߷� ����
        obj->UpdatePosition(deltaTime); // ��ġ ������Ʈ
        objects.Move();
    }
    ReleaseMutex(hMutex);  // ���ؽ� ����
}




void DPhysicsManager::ResolveCollisions() {
    DWORD result = WaitForSingleObject(hMutex, INFINITE);  // ���ؽ� ���
    for (int i = 0; i < objects.GetSize(); i++) {
        DCollisionData* objA = objects.GetValue();
        //objects.Move();  // ���� ��ü�� �̵�

        for (int j = 1; j < objects.GetSize(); j++) {
            objects.Move();  // ���� ��ü�� �̵�
            DCollisionData* objB = objects.GetValue();
            DCollisionDetector detector(objA, objB);
            if (detector.DetectCollision()) {
                objA->OnCollision(objB);


                //DEngine::LogMessageBox("�浹");
                // �浹 ó��
                //detector.ResolveCollision(objA, objB);

            }
            
        }
        //objects.Move();  // ���� ��ü�� �̵�
        
    }
    ReleaseMutex(hMutex);  // ���ؽ� ����
}

    


void DPhysicsManager::SetParent(DCollisionData* parent, DCollisionData* child) {
    DWORD result = WaitForSingleObject(hMutex, INFINITE);  // ���ؽ� ���    
    child->SetParent(parent); 
    parent->AddChild(child);
    ReleaseMutex(hMutex);  // ���ؽ� ����
}

void DPhysicsManager::RemoveParent(DCollisionData* child) {
    DWORD result = WaitForSingleObject(hMutex, INFINITE);  // ���ؽ� ���
    DCollisionData* parent = child->GetParent();
    if (parent) {
        parent->RemoveChild(child); 
        child->SetParent(nullptr);  
    }
    ReleaseMutex(hMutex);  // ���ؽ� ����
}
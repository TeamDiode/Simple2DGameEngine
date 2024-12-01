#include "DPhysicsManager.h"
#include "DCollision.h"
#include "DEngine.h"

DList<DCollisionData*> DPhysicsManager::objects = DList<DCollisionData*>();

DPhysicsManager::DPhysicsManager()
{
    gravity = DGravity(700); // 임시
    hMutex = CreateMutex(NULL, false, NULL);
}

DPhysicsManager::~DPhysicsManager()
{
    CloseHandle(hMutex);
}

void DPhysicsManager::AddObject(DCollisionData* object) {    
    //DWORD result = WaitForSingleObject(hMutex, INFINITE);  // 뮤텍스 잠금
    objects.AddNext(object); // 객체 추가
    //ReleaseMutex(hMutex);  // 뮤텍스 해제
}

void DPhysicsManager::UpdateObjects(float deltaTime) {
    DWORD result = WaitForSingleObject(hMutex, INFINITE);  // 뮤텍스 잠금
    for (int i = 0; i < objects.GetSize(); i++) {
        DCollisionData* obj = objects.GetValue();

        gravity.ApplyGravity(*obj, deltaTime); // 중력 적용
        obj->UpdatePosition(deltaTime); // 위치 업데이트
        objects.Move();
    }
    ReleaseMutex(hMutex);  // 뮤텍스 해제
}




void DPhysicsManager::ResolveCollisions() {
    DWORD result = WaitForSingleObject(hMutex, INFINITE);  // 뮤텍스 잠금
    for (int i = 0; i < objects.GetSize(); i++) {
        DCollisionData* objA = objects.GetValue();
        //objects.Move();  // 다음 객체로 이동

        for (int j = 1; j < objects.GetSize(); j++) {
            objects.Move();  // 다음 객체로 이동
            DCollisionData* objB = objects.GetValue();
            DCollisionDetector detector(objA, objB);
            if (detector.DetectCollision()) {
                objA->OnCollision(objB);


                //DEngine::LogMessageBox("충돌");
                // 충돌 처리
                //detector.ResolveCollision(objA, objB);

            }
            
        }
        //objects.Move();  // 다음 객체로 이동
        
    }
    ReleaseMutex(hMutex);  // 뮤텍스 해제
}

    


void DPhysicsManager::SetParent(DCollisionData* parent, DCollisionData* child) {
    DWORD result = WaitForSingleObject(hMutex, INFINITE);  // 뮤텍스 잠금    
    child->SetParent(parent); 
    parent->AddChild(child);
    ReleaseMutex(hMutex);  // 뮤텍스 해제
}

void DPhysicsManager::RemoveParent(DCollisionData* child) {
    DWORD result = WaitForSingleObject(hMutex, INFINITE);  // 뮤텍스 잠금
    DCollisionData* parent = child->GetParent();
    if (parent) {
        parent->RemoveChild(child); 
        child->SetParent(nullptr);  
    }
    ReleaseMutex(hMutex);  // 뮤텍스 해제
}
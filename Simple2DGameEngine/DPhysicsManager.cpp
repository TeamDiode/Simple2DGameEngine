#include "DPhysicsManager.h"
#include "DCollision.h"
#include "DEngine.h"

DList<DCollisionData*> DPhysicsManager::objects = DList<DCollisionData*>();

DPhysicsManager::DPhysicsManager()
{
    gravity = DGravity(700); // 임시
}

void DPhysicsManager::AddObject(DCollisionData* object) {    
    objects.AddNext(object); // 객체 추가
}

void DPhysicsManager::UpdateObjects(float deltaTime) {
    for (int i = 0; i < objects.GetSize(); i++) {
        DCollisionData* obj = objects.GetValue();

        gravity.ApplyGravity(*obj, deltaTime); // 중력 적용
        obj->UpdatePosition(deltaTime); // 위치 업데이트
        objects.Move();
    }
}




void DPhysicsManager::ResolveCollisions() {
    for (int i = 0; i < objects.GetSize(); i++) {
        DCollisionData* objA = objects.GetValue();
        //objects.Move();  // 다음 객체로 이동

        for (int j = 1; j < objects.GetSize(); j++) {
            objects.Move();  // 다음 객체로 이동
            DCollisionData* objB = objects.GetValue();
            DCollisionDetector detector(objA, objB);
            if (detector.DetectCollision()) {
                objA->OnCollision(objB);


                DEngine::LogMessageBox("충돌");
                // 충돌 처리
                //detector.ResolveCollision(objA, objB);

            }
            
        }
        //objects.Move();  // 다음 객체로 이동
        
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
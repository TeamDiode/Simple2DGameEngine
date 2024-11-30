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
        obj->SyncWithLinkedObject();

        gravity.ApplyGravity(*obj, deltaTime); // 중력 적용
        obj->UpdatePosition(deltaTime); // 위치 업데이트
        objects.Move();
    }
}




void DPhysicsManager::ResolveCollisions() {
    for (int i = 0; i < objects.GetSize(); i++) {
        DCollisionData* objA = objects.GetValue();
        objects.Move();  // 다음 객체로 이동

        for (int j = i + 1; j < objects.GetSize(); j++) {
            DCollisionData* objB = objects.GetValue();
            DCollisionDetector detector(objA, objB);
            if (detector.DetectCollision()) {
                DEngine::LogMessageBox("충돌");
                
                // 충돌한 객체들을 서로에게 등록
                objA->RegisterCollisionEvent(objB);
                objB->RegisterCollisionEvent(objA);

                // 충돌 처리
                detector.ResolveCollision(*objA, *objB);

                // 충돌한 객체를 반환해서 처리
                DCollisionData* otherA = objA->GetOtherObject();
                DCollisionData* otherB = objB->GetOtherObject();
                
            }
        }

        objects.Move();  // 다음 객체로 이동
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
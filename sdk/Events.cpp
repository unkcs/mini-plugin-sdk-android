#include <mod/amlmod.h>
#include <game_sa/sdk.h>
#include <sdk/Call.h>

#include "Events.h"

CEvents renderCloudsEvent(renderClouds); 
CEvents initScriptsEvent(initScripts);
CEvents processScriptsEvent(processScripts);
CEvents initRwEvent(initRw);
CEvents initPoolsEvent(initPools);
CEvents pedCtorEvent(pedCtor);
CEvents pedDtorEvent(pedDtor);
CEvents pedRenderEvent(pedRender);
CEvents objectRenderEvent(objectRender);
CEvents objectPreRenderEvent(objectPreRender);
CEvents touchEvent(touch);
CEvents drawHudEvent(drawHud);
CEvents drawingEvent(drawing);
CEvents drawAfterFadeEvent(drawAfterFade);
CEvents drawRadarEvent(drawRadar);
CEvents drawBlipsEvent(drawBlips);
CEvents drawRadarOverlayEvent(drawRadarOverlay);
CEvents drawMenuEvent(drawMenu);

// new events
CEvents vehicleRenderEvent(vehicleRender);

void CEvents::pedRenderCalls(CPed* ped) {
    for(pedRenderEvent.PedPtr = pedRenderEvent.PedEvents.begin(); pedRenderEvent.PedPtr != pedRenderEvent.PedEvents.end(); ++pedRenderEvent.PedPtr){
        EventPtrPed func = *pedRenderEvent.PedPtr;
        func(ped);
    }
}

DECL_HOOKv(PedRenderHook, CPed* ped) {
    CEvents::pedRenderCalls(ped);
    PedRenderHook(ped);
}

void CEvents::drawingCalls(){
    for(drawingEvent.actPtr = drawingEvent.events.begin(); drawingEvent.actPtr != drawingEvent.events.end(); ++drawingEvent.actPtr) {
        EventPtr func = *drawingEvent.actPtr;
        func();
    }
}

DECL_HOOKv(drawingHook) {
    CEvents::drawingCalls();
    drawingHook();
}

void CEvents::drawAfterFadeCalls() {
    for(drawAfterFadeEvent.actPtr = drawAfterFadeEvent.events.begin(); drawAfterFadeEvent.actPtr != drawAfterFadeEvent.events.end(); ++drawAfterFadeEvent.actPtr) {
        EventPtr func = *drawAfterFadeEvent.actPtr;
        func();
    }
}

DECL_HOOKv(drawAfterFadeHook) {
    CEvents::drawAfterFadeCalls();
    drawAfterFadeHook();
}

void CEvents::vehicleRenderCalls(CVehicle* veh) {
    for(vehicleRenderEvent.VehPtr = vehicleRenderEvent.VehEvents.begin(); vehicleRenderEvent.VehPtr !=  vehicleRenderEvent.VehEvents.end(); ++vehicleRenderEvent.VehPtr) {
        EventPtrVeh func = *vehicleRenderEvent.VehPtr;
        func(veh);
    }
}

DECL_HOOKv(vehicleRenderHook, CVehicle* veh) {
    CEvents::vehicleRenderCalls(veh);
    vehicleRenderHook(veh);
}

void CEvents::drawBlipsCalls(float size) {
    for(drawBlipsEvent.blipsPtr = drawBlipsEvent.blipsEvents.begin(); drawBlipsEvent.blipsPtr != drawBlipsEvent.blipsEvents.end(); ++drawBlipsEvent.blipsPtr) {
        EventPtrBlips func = *drawBlipsEvent.blipsPtr;
        func(size);
    }
}

DECL_HOOKp(drawBlipsHook, float size) {
    CEvents::drawBlipsCalls(size);
    return drawBlipsHook(size);
}

void CEvents::objectPreRenderCalls(CObject* obj) {
    for(objectPreRenderEvent.ObjPtr = objectPreRenderEvent.ObjEvents.begin(); objectPreRenderEvent.ObjPtr != objectPreRenderEvent.ObjEvents.end(); ++objectPreRenderEvent.ObjPtr) {
        EventPtrObj func = *objectPreRenderEvent.ObjPtr;
        func(obj);
    }
}

DECL_HOOKv(objectPreRenderHook, CObject* obj) {
    CEvents::objectPreRenderCalls(obj);
    objectPreRenderHook(obj);
}

void CEvents::objectRenderCalls(CObject* obj) {
    for(objectRenderEvent.ObjPtr = objectRenderEvent.ObjEvents.begin(); objectRenderEvent.ObjPtr != objectRenderEvent.ObjEvents.end(); ++objectRenderEvent.ObjPtr) {
        EventPtrObj func = *objectRenderEvent.ObjPtr;
        func(obj);
    }
}

DECL_HOOKv(objectRenderHook, CObject* obj) {
    CEvents::objectRenderCalls(obj);
    objectRenderHook(obj);
}

void CEvents::initRwCalls() {
    for(initRwEvent.actPtr = initRwEvent.events.begin(); initRwEvent.actPtr != initRwEvent.events.end(); ++initRwEvent.actPtr) {
        EventPtr func = *initRwEvent.actPtr;
        func();
    }
}

DECL_HOOKi(initRwHook) {
    CEvents::initRwCalls();
    return initRwHook();
}

void CEvents::initPoolsCalls() {
    for(initPoolsEvent.actPtr = initPoolsEvent.events.begin(); initPoolsEvent.actPtr != initPoolsEvent.events.end(); ++initPoolsEvent.actPtr) {
        EventPtr func = *initPoolsEvent.actPtr;
        func();
    }
}

DECL_HOOKi(initPoolsHook) {
    CEvents::initPoolsCalls();
    return initPoolsHook();
}

void CEvents::drawMenuCalls(void* gMobileMenu) {
    for(drawMenuEvent.mobMenuPtr = drawMenuEvent.mobMenuEvents.begin(); drawMenuEvent.mobMenuPtr != drawMenuEvent.mobMenuEvents.end(); ++drawMenuEvent.mobMenuPtr) {
        EventPtrMob func = *drawMenuEvent.mobMenuPtr;
        func(gMobileMenu);
    }
}

DECL_HOOKv(drawMenuHook, void* gMobileMenu) {
    CEvents::drawMenuCalls(gMobileMenu);
    drawMenuHook(gMobileMenu);
}

void CEvents::drawRadarCalls() {
    for(drawRadarEvent.actPtr = drawRadarEvent.events.begin(); drawRadarEvent.actPtr != drawRadarEvent.events.end(); ++drawRadarEvent.actPtr) {
        EventPtr func = *drawRadarEvent.actPtr;
        func();
    }
}

DECL_HOOKi(drawRadarHook) {
    CEvents::drawRadarCalls();
    return drawRadarHook();
}

void CEvents::drawRadarOverlayCalls(bool inMenu) {
    for(drawRadarOverlayEvent.radarPtr = drawRadarOverlayEvent.radarEvents.begin(); drawRadarOverlayEvent.radarPtr != drawRadarOverlayEvent.radarEvents.end(); ++drawRadarOverlayEvent.radarPtr) {
        EventPtrRadarOv func = *drawRadarOverlayEvent.radarPtr;
        func(inMenu);
    }
}

DECL_HOOKv(drawRadarOverlayHook, bool inMenu) {
    CEvents::drawRadarOverlayCalls(inMenu);
    drawRadarOverlayHook(inMenu);
}

void CEvents::processScriptsCalls() {
    for(processScriptsEvent.actPtr = processScriptsEvent.events.begin(); processScriptsEvent.actPtr != processScriptsEvent.events.end(); ++processScriptsEvent.actPtr) {
        EventPtr func = *processScriptsEvent.actPtr;
        func();
    }
}

DECL_HOOKv(processScriptsHook) {
    CEvents::processScriptsCalls();
    processScriptsHook();
}

void CEvents::touchCalls(NVTouchEventType actionType, int trackNum, int x, int y) {
    for(touchEvent.TouchPtr = touchEvent.TouchEvents.begin(); touchEvent.TouchPtr != touchEvent.TouchEvents.end(); ++touchEvent.TouchPtr) {
        EventPtrTouch func = *touchEvent.TouchPtr;
        func(actionType, trackNum, x, y);
    }
}

DECL_HOOKv(touchHook, NVTouchEventType actionType, int trackNum, int x, int y) {
    CEvents::touchCalls(actionType, trackNum, x, y);
    touchHook(actionType, trackNum, x, y);
}

void CEvents::initScriptsCalls() {
    for(initScriptsEvent.actPtr = initScriptsEvent.events.begin(); initScriptsEvent.actPtr != initScriptsEvent.events.end(); ++initScriptsEvent.actPtr) {
        EventPtr func = *initScriptsEvent.actPtr;
        func();
    }
}

DECL_HOOKi(initScriptsHook) {
    CEvents::initScriptsCalls();
    return initScriptsHook();
}

void CEvents::renderCloudsCalls() {
    for(renderCloudsEvent.actPtr = renderCloudsEvent.events.begin(); renderCloudsEvent.actPtr != renderCloudsEvent.events.end(); ++renderCloudsEvent.actPtr) {
        EventPtr func = *renderCloudsEvent.actPtr;
        func();
    }
}

DECL_HOOKi(renderCloudsHook) {
    CEvents::renderCloudsCalls();
    return renderCloudsHook();
}

void CEvents::pedCtorCalls(CPed* ped) {
    for(pedRenderEvent.PedPtr = pedRenderEvent.PedEvents.begin(); pedRenderEvent.PedPtr != pedRenderEvent.PedEvents.end(); ++pedRenderEvent.PedPtr){
        EventPtrPed func = *pedRenderEvent.PedPtr;
        func(ped);
    }
}

DECL_HOOKv(pedCtorHook, CPed* ped) {
    CEvents::pedCtorCalls(ped);
    pedCtorHook(ped);
}

void CEvents::pedDtorCalls(CPed* ped) {
    for(pedRenderEvent.PedPtr = pedRenderEvent.PedEvents.begin(); pedRenderEvent.PedPtr != pedRenderEvent.PedEvents.end(); ++pedRenderEvent.PedPtr){
        EventPtrPed func = *pedRenderEvent.PedPtr;
        func(ped);
    }
}

DECL_HOOKv(pedDtorHook, CPed* ped) {
    CEvents::pedDtorCalls(ped);
    pedDtorHook(ped);
}

CEvents::CEvents(EventsType type) {
    switch(type){
        case drawBlips:
            HOOKPLT(drawBlipsHook, 0x66E910 + libs.pGame);
            break;
        case initPools:
            HOOKPLT(initPoolsHook, 0x672468 + libs.pGame);
            break;
        case initRw:
            HOOKPLT(initRwHook, 0x66F2D0 + libs.pGame);
            break;
        case objectPreRender:
            HOOKBLX(objectPreRenderHook, GetSym("_ZN7CObject9PreRenderEv") + 0x1B0);
            break;
        case objectRender:
            HOOKBLX(objectRenderHook, GetSym("_ZN7CObject6RenderEv") + 0x6A);
            break;
        case drawMenu:
            HOOKPLT(drawMenuHook, 0x674254 + libs.pGame);
            break;
        case drawRadar:
            HOOKPLT(drawRadarHook, 0x66F618 + libs.pGame);
            break;
        case drawRadarOverlay:
            HOOKPLT(drawRadarOverlayHook, 0x67196C + libs.pGame);
            break;
        case touch:
            HOOKPLT(touchHook, 0x675DE4 + libs.pGame);
            break;
        case initScripts:
            HOOKPLT(initScriptsHook, 0x671B14 + libs.pGame);
            break;
        case renderClouds:
            HOOKPLT(renderCloudsHook, 0x672FFC + libs.pGame);
            break;
        case vehicleRender:
            HOOKB(vehicleRenderHook, GetSym("_ZN8CVehicle6RenderEv") + 0xE6);
            break;
        case processScripts:
            HOOKPLT(processScriptsHook, 0x672AAC + libs.pGame);
            break;
        case pedCtor:
            HOOKBLX(pedCtorHook, GetSym("_ZN4CPedC2Ej") + 0x12);
            break;
        case pedDtor:
            HOOKB(pedDtorHook, GetSym("_ZN4CPedD2Ev") + 0x156);
            break;
        case pedRender:
            HOOKBLX(PedRenderHook, GetSym("_ZN4CPed6RenderEv") + 0xBE);
            break;
        case drawing:   
            HOOKBLX(drawingHook, GetSym("_Z13Render2dStuffv") + 0x48);
            break;
        case drawAfterFade:
            HOOKPLT(drawAfterFadeHook, 0x673C4C + libs.pGame);
            break;    
        default:
            break;
    }
}
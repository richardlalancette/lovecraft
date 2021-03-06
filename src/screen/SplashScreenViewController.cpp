#include "SplashScreenViewController.h"

#include "customviews/TabbedView.h"
#include "screen/TabbedViewController.h"
#include "utilities/NodeUtilities.h"

#include <animation/YiAbstractTimeline.h>
#include <framework/YiApp.h>
#include <framework/YiFramework.h>
#include <view/YiPushButtonView.h>

/*
// Load a layout file which will be the root scene view.
CYISceneView *pSceneViewMain = GetSceneManager()->LoadScene("MainNav_Main.layout", CYISceneManager::SCALE_STRETCH, CYISceneManager::V_ALIGN_CENTER, CYISceneManager::H_ALIGN_CENTER);

if(!pSceneViewMain)
{
YI_LOGE("LovecraftApp::UserInit", "Loading scene has failed");
return false;
}

pSceneViewMain->GetInTimeline()->StartForward();

// Add the scene view to the scene manager.
GetSceneManager()->AddScene("MainComp", pSceneViewMain, 0, CYISceneManager::LAYER_OPAQUE);
*/


SplashScreenViewController::SplashScreenViewController(NavigationInterface &navigationInterface, CYIApp &app) :
     //TabbedScreenViewController(NavigationInterface::SPLASH, "SplashScreen", "Splash_Main.layout", navigationInterface, app)
     TabbedScreenViewController(NavigationInterface::SPLASH, "SplashScreen", "MainNav_Main.layout", navigationInterface, app)
    , m_tabbedViewController(navigationInterface)
    , m_pTabbedView(YI_NULL)
    , m_pButtonBarView(YI_NULL)
{
}

SplashScreenViewController::~SplashScreenViewController()
{
}

void SplashScreenViewController::BuildTimelines()
{
    m_pInTimeline = m_pView->BuildTimelineGroup("In");
    if (m_pInTimeline)
    {
        SetBeginAnimation(m_pInTimeline.Get(), TimelineHelper::ANIMATE_FORWARD);
    }

    m_pOutTimeline = m_pView->BuildTimelineGroup("Out");
    if (m_pOutTimeline)
    {
        SetEndAnimation(m_pOutTimeline.Get(), TimelineHelper::ANIMATE_FORWARD);
    }    
}

void SplashScreenViewController::OnInitScreen()
{
    TabbedScreenViewController::OnInitScreen();

    //m_pTabbedView = Utility::GetNode<TabbedView>(m_pView, "TabbedView");
    //m_pButtonBarView = Utility::GetNode<ButtonBarView>(m_pView, "ButtonBar");

    //m_tabbedViewController.Init(m_pTabbedView);

    //m_pBackButton = Utility::GetNode<CYIPushButtonView>(m_pView, "Btn-Back");
}

void SplashScreenViewController::OnPreloadValidateScreen(CYIBundle)
{
    PreloadValidateSucceeded.Emit(this);
}

void SplashScreenViewController::OnPreloadScreen(CYIBundle bundle, const CYIPersistentStore &stateData)
{
    TabbedScreenViewController::OnPreloadScreen(bundle, stateData);

    PreloadFinished(this);
}


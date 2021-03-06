#ifndef _SPLASH_SCREEN_VIEW_CONTROLLER_H_
#define _SPLASH_SCREEN_VIEW_CONTROLLER_H_

#include "customviews/ButtonBarView.h"
#include "screen/TabbedScreenViewController.h"

#include <animation/YiTimelineGroup.h>
#include <smartptr/YiScopedPtr.h>

class TabbedView;
class ButtonBarView;
class CYITimelineGroup;

class SplashScreenViewController : public TabbedScreenViewController
{
public:
    SplashScreenViewController(NavigationInterface &navigationInterface, CYIApp &app);
    virtual ~SplashScreenViewController();

protected:
    virtual void OnInitScreen();
    virtual void OnPreloadValidateScreen(CYIBundle);
    virtual void OnPreloadScreen(CYIBundle bundle, const CYIPersistentStore &stateData);

    virtual void BuildTimelines();

private:
    CYIScopedPtr<CYITimelineGroup> m_pInTimeline;
    CYIScopedPtr<CYITimelineGroup> m_pOutTimeline;

    TabbedViewController m_tabbedViewController;
    TabbedView *m_pTabbedView;
    ButtonBarView *m_pButtonBarView;

    YI_DISALLOW_COPY_AND_ASSIGN(SplashScreenViewController)
};

#endif


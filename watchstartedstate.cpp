#include "watchstartedstate.h"
#include "iwatchcontext.h"
#include "watchstoppedstate.h"
#include "watchpausedstate.h"

#include <iostream>
#include <cassert>

using namespace std;

WatchStartedState::WatchStartedState(IWatchContext *context)
    : IWatchState(context)
{
}

void WatchStartedState::_start()
{
    cout << "Start watch: already started\n";
}

void WatchStartedState::_stop()
{
    cout << "Stop watch: new STATE = STOPPED\n";
    w->set_state(new WatchStoppedState(w));
}

void WatchStartedState::_pause()
{
    cout << "Pause watch: new STATE = PAUSED\n";
    w->set_state(new WatchPausedState(w));
}

//
//  streaming_view.hpp
//  Moonlight
//
//  Created by Даниил Виноградов on 27.05.2021.
//

#pragma once

#include <borealis.hpp>
#include <Settings.hpp>
#include "GameStreamClient.hpp"
#include "MoonlightSession.hpp"
#include "loading_overlay.hpp"

using namespace brls;

class StreamingView : public Box
{
public:
    StreamingView(Host host, AppInfo app);
    ~StreamingView();
    
    void draw(NVGcontext* vg, float x, float y, float width, float height, Style style, FrameContext* ctx) override;
    void onFocusGained() override;
    void onFocusLost() override;
    void onLayout() override;
    
    void terminate();
    
private:
    bool draw_stats = true;
    Host host;
    AppInfo app;
    MoonlightSession* session;
    LoadingOverlay* loader = nullptr;
    
    void handleInput();
    void handleButtonHolding();
};
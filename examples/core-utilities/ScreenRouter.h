#pragma once
#include <stdint.h>

enum class ScreenId : uint8_t {
    Habitat = 0,
    MainMenu,
    Inventory,
    Signalpedia,
    Rest,
    Training,
    Battle,
    Stats,
    Shop,
    Log,
    Clock,
    Settings,
    About,
    RivalBook,
    LineageArchive,
    Diagnostics,
    Incubation,
    ResetConfirm,
    HatchSequence,
    EvolutionSequence,
    DepartureSequence
};
inline bool isOrdinaryScreen(ScreenId screen) {
    return screen != ScreenId::ResetConfirm &&
           screen != ScreenId::HatchSequence &&
           screen != ScreenId::EvolutionSequence &&
           screen != ScreenId::DepartureSequence &&
           screen != ScreenId::Incubation;
}
class ScreenRouter {
public:
    static constexpr uint8_t HISTORY_CAPACITY = 8;
    void reset(ScreenId initial = ScreenId::Habitat) { current_=initial; depth_=0; }
    ScreenId current() const { return current_; }
    bool go(ScreenId next, bool remember=true) {
        if (next==current_) return false;
        if (remember && isOrdinaryScreen(current_) && isOrdinaryScreen(next)) push(current_);
        current_=next; return true;
    }
    bool back() {
        if (!isOrdinaryScreen(current_) || depth_==0) return false;
        current_=history_[--depth_]; return true;
    }
    void force(ScreenId next) { current_=next; depth_=0; }
    uint8_t historyDepth() const { return depth_; }
private:
    void push(ScreenId screen) {
        if (depth_>0 && history_[depth_-1]==screen) return;
        if (depth_<HISTORY_CAPACITY) { history_[depth_++]=screen; return; }
        for (uint8_t i=1;i<HISTORY_CAPACITY;++i) history_[i-1]=history_[i];
        history_[HISTORY_CAPACITY-1]=screen;
    }
    ScreenId current_=ScreenId::Habitat;
    ScreenId history_[HISTORY_CAPACITY]{};
    uint8_t depth_=0;
};

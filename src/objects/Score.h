#ifndef SCORE_H
#define SCORE_H

#include "default/GameObject.h"

class Score : public GameObject {
    int score_;
public:
    Score() : GameObject{} {};
    Score(float x, float y) : GameObject{ x, y } {};
    Score(int score) : score_{ score } {};
    Score(int score, float x, float y) : GameObject{ x, y }, score_{ score } {}
    int GetScore() { return score_; }
    int IncrementScore() { return ++score_; }
    void ClearScore() { score_ = 0; }
    void Render() override;
};

#endif // !SCORE_H
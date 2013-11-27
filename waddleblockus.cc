#include "waddleblockus.h"

WaddleBlockus::WaddleBlockus(int x, int y) : Being(x, y) {
    Point torso_position = Point(0, 16);
    Rectangle torso_box(0, 16, 128, 96);
    std::vector<Point> torso_frames;
    torso_frames.push_back(torso_position);
    torso_frames.push_back(torso_position);
    torso_frames.push_back(torso_position);
    torso_frames.push_back(torso_position);
    torso_frames.push_back(torso_position);
    torso_frames.push_back(torso_position);
    BodyPart torso("torso", torso_box, torso_frames);
    addPart(torso);

    Point head_position = Point(128, 56);
    Rectangle head_box(128, 56, 16, 16);
    std::vector<Point> head_frames;
    head_frames.push_back(head_position);
    head_frames.push_back(head_position);
    head_frames.push_back(head_position);
    head_frames.push_back(head_position);
    head_frames.push_back(head_position);
    head_frames.push_back(head_position);
    BodyPart head("head", head_box, head_frames);
    addPart(head);

    Point front_left_leg_position = Point(112, 0);
    Rectangle front_left_leg_box(112, 0, 16, 16);
    std::vector<Point> front_left_leg_frames;
    front_left_leg_frames.push_back(Point(112, 0));
    front_left_leg_frames.push_back(Point(110, 0));
    front_left_leg_frames.push_back(Point(108, 0));
    front_left_leg_frames.push_back(Point(106, 0));
    front_left_leg_frames.push_back(Point(108, 0));
    front_left_leg_frames.push_back(Point(110, 0));
    BodyPart front_left_leg("front-left leg",
                            front_left_leg_box,
                            front_left_leg_frames);
    addPart(front_left_leg);

    Point front_right_leg_position = Point(106, 112);
    Rectangle front_right_leg_box(106, 112, 16, 16);
    std::vector<Point> front_right_leg_frames;
    front_right_leg_frames.push_back(Point(106, 112));
    front_right_leg_frames.push_back(Point(108, 112));
    front_right_leg_frames.push_back(Point(110, 112));
    front_right_leg_frames.push_back(Point(112, 112));
    front_right_leg_frames.push_back(Point(110, 112));
    front_right_leg_frames.push_back(Point(108, 112));
    BodyPart front_right_leg("front-right leg",
                            front_right_leg_box,
                            front_right_leg_frames);
    addPart(front_right_leg);

    Point back_left_leg_position = Point(6, 0);
    Rectangle back_left_leg_box(6, 0, 16, 16);
    std::vector<Point> back_left_leg_frames;
    back_left_leg_frames.push_back(Point(6, 0));
    back_left_leg_frames.push_back(Point(4, 0));
    back_left_leg_frames.push_back(Point(2, 0));
    back_left_leg_frames.push_back(Point(0, 0));
    back_left_leg_frames.push_back(Point(2, 0));
    back_left_leg_frames.push_back(Point(4, 0));
    BodyPart back_left_leg("back-left leg",
                            back_left_leg_box,
                            back_left_leg_frames);
    addPart(back_left_leg);

    Point back_right_leg_position = Point(0, 112);
    Rectangle back_right_leg_box(0, 112, 16, 16);
    std::vector<Point> back_right_leg_frames;
    back_right_leg_frames.push_back(Point(0, 112));
    back_right_leg_frames.push_back(Point(2, 112));
    back_right_leg_frames.push_back(Point(4, 112));
    back_right_leg_frames.push_back(Point(6, 112));
    back_right_leg_frames.push_back(Point(4, 112));
    back_right_leg_frames.push_back(Point(2, 112));
    BodyPart back_right_leg("back-right leg",
                            back_right_leg_box,
                            back_right_leg_frames);
    addPart(back_right_leg);
}

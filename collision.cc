#include "collision.h"

bool rectanglesCollide(Rectangle rectangle_a, Rectangle rectangle_b)
{
    return (abs(rectangle_a.x - rectangle_b.x) * 2 <
           (rectangle_a.width + rectangle_b.width))
           &&
           (abs(rectangle_a.y - rectangle_b.y) * 2 <
           (rectangle_a.height + rectangle_b.height));
}

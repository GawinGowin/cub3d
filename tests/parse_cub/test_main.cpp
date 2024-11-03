#include <gtest/gtest.h>

extern "C"
{
	#include "cub3d.h"
}

#include "compare_operators.h"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

bool operator==(const t_param_cub &a, const t_param_cub &b) {
    if (a.floor != b.floor || a.ceiling != b.ceiling) {
        return false;
    }
    if (a.map_width != b.map_width || a.map_height != b.map_height) {
        return false;
    }
    for (size_t i = 0; i < a.map_height; i++) {
        if (strcmp(a.map[i], b.map[i]) != 0) {
            return false;
        }
    }
    return true;
}

bool operator==(const t_player &a, const t_player &b) {
	return a.pos_x == b.pos_x && a.pos_y == b.pos_y && a.angle == b.angle;
}

bool operator!=(const t_texture &a, const t_texture &b) {
	return a.img != b.img || a.addr != b.addr || a.width != b.width || a.height != b.height;
}

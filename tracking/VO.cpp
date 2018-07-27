//
// Created by pidan1231239 on 18-7-13.
//

#include "VO.h"

namespace sky {

    void VO::step(const Mat &image) {
        KeyFrame::Ptr keyFrame(new KeyFrame(camera, image, feature2D));
        switch (state) {
            //初始化状态
            case 0: {
                if (initializer->step(keyFrame)) {
                    //保存初始化的地图
                    localMap->init(initializer->initialMap);
                    state = 1;
                    initializer = nullptr;
                }
                break;
            }
                //追踪状态
            case 1: {
                tracker->step(keyFrame);
                break;
            }
        }
    }

}

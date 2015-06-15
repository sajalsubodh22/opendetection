//
// Created by sarkar on 03.06.15.
//

#ifndef OPENDETECTION_OBJECTDETECTOR_H
#define OPENDETECTION_OBJECTDETECTOR_H

#include <jmorecfg.h>
#include <string>
#include <vector>

using namespace std;

namespace od
{

  class ODScene;
  class ODDetection;

  enum DetectionMethod {
    PC_GLOBAL_FEATUREMATCHING,
    PC_LOCAL_CORRESPONDENCE_GROUPING,
    IMAGE_LOCAL_SIMPLE,
    IMAGE_GLOBAL_DENSE,
    IMAGE_GLOBAL_CLASSIFICATION,
  };

  /** \brief This is the main class for object detection and recognition.
   *
   *
   * \author Kripasindhu Sarkar
   *
   */
  class ObjectDetector {
  public:


    ObjectDetector()
    { }

    DetectionMethod const &getMethod() const
    {
      return method_;
    }

    void setDetectionMethod(DetectionMethod const &detection_method_)
    {
      this->method_ = detection_method_;
    }

    bool getAlwaysTrain() const
    {
      return always_train_;
    }

    void setAlwaysTrain(boolean always_train_)
    {
      this->always_train_ = always_train_;
    }

    string getTrainingInputLocation() const
    {
      return training_input_location_;
    }

    void setTrainingInputLocation(string training_input_location_)
    {
      this->training_input_location_ = training_input_location_;
    }

    string getTrainingDataLocation() const
    {
      return training_data_location_;
    }

    void setTrainingDataLocation(string training_data_location_)
    {
      this->training_data_location_ = training_data_location_;
    }

    virtual void init() = 0;

    virtual int train() = 0;


    virtual int detect(ODScene *scene, std::vector<ODDetection *> detections) = 0;

  protected:
    DetectionMethod method_;
    bool always_train_;
    string training_input_location_, training_data_location_;
  };

}

#endif //OPENDETECTION_OBJECTDETECTOR_H

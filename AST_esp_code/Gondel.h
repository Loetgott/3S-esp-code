#import <Zone.h>

class Gondola{
  private:
    int id;
    bool isStopped;
    Zone zone;
    short progress

  public:

    Gondola(int nId){
      id = nId;
    }

    void setZone(Zone nZone) {
      zone = nZone;
    }

    void setProgress(short nProgress) {
      progress = nProgress;
    }

    void updatePosition(int steps){

    }

    void setIsStopped(bool nIsStopped){
      isStopped = nIsStopped;
    }
};
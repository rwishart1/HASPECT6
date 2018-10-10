// Author: Michael Williams 2018 
// Modified: Derek Glazier 2018

/**********************************************************************************
* Project: HSFinalState 			                                 *
* Package:                                                                      *
* Class  : MVASignalID                                                            *
*                                                                                *
* Description:                                                                   *
*                                                                                * 
*     Tree in THSFinalState                                                      *
*     Given a THSParticle it will create default branches                        *
*     from datamembers of the THSParticle class                                  *
*     For each combitorial event it will then fill the tree                      *
*                                                                                *
**********************************************************************************/
#ifndef HSFS_MVASIGNALID_h
#define HSFS_MVASIGNALID_h

#include "THSParticle.h"
#include "TreePrepBase.h"
#include "VarsParticle.h"
#include "ResultInterface.h"

namespace HS{


  class MVASignalID : public VarsParticle {

  public:
    //    MVASignalID(TString tname,TString fname):TreePrepBase(tname,fname){};
    MVASignalID(){};
    virtual ~MVASignalID()=default;
 
    void SetVarLinks();
    Float_t  Eval(){
      VarsParticle::FillVars();
      return fResult.get()->Eval();
    };
  
 
    void CreateResult(TString methname,TString dirname);

private:
 

    unique_ptr<HS::MVA::ResultByRefLink> fResult;

    HS::MVA::mapNameFloat fParticleLinks;

  };//class MVASignalID

};//namespace HSFinalState

#endif //

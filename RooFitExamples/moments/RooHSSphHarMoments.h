/*****************************************************************************
 * Project: RooFit                                                           *
 *                                                                           *
  * This code was autogenerated by RooClassFactory                            * 
 *****************************************************************************/

#ifndef ROOHSSPHHARMOMENTS
#define ROOHSSPHHARMOMENTS

#include "RooAbsPdf.h"
#include "RooHSEventsPDF.h"
#include "RooRealProxy.h"
#include "RooCategoryProxy.h"
#include "RooAbsReal.h"
#include "RooRealVar.h"
#include "RooAbsCategory.h"
#include "RooListProxy.h"
#include <vector> 

class RooHSSphHarMoments : public RooHSEventsPDF {
public:
  RooHSSphHarMoments() {} ; 
  RooHSSphHarMoments(const char *name, const char *title,
	      RooAbsReal& _Z,
	      RooAbsReal& _Phi,
	      Int_t _Lmax,
	      Int_t _Mmax);
  RooHSSphHarMoments(const char *name, const char *title,
	      RooAbsReal& _Z,
	      RooAbsReal& _Phi,
		Int_t _Lmax,
		Int_t _Mmax,
	      const RooArgList& coefList);
  RooHSSphHarMoments(const RooHSSphHarMoments& other, const char* name=0) ;
  virtual TObject* clone(const char* newname) const { return new RooHSSphHarMoments(*this,newname); }
  inline virtual ~RooHSSphHarMoments();
  
  static RooArgSet CreateMoments(Int_t L,Int_t _Mmax=2);
  static Double_t evalN(Int_t _L,Int_t _M) ;
  Double_t evalRealSphHarmonic(Double_t _Z,Double_t _Phi,Int_t _L,Int_t _M) const;
  Double_t evalLegendre(Double_t _Z,Int_t _L,Int_t _M) const;
  
  protected:
  Double_t fMCZ=0;
  Double_t fMCPhi=0;

  RooRealProxy Z ;
  RooRealProxy Phi ;
  Int_t Lmax=0 ;
  Int_t Mmax=0 ;

  Double_t evaluate() const ;
  Double_t evaluateMC() const ;
  void MakeSets();

  //vector<RooRealProxy> fMoms;
  RooListProxy fMoms;
  RooArgSet* fYSet=nullptr;
  
  /* Int_t getAnalyticalIntegral(RooArgSet& allVars, RooArgSet& analVars,const char* rangeName) const; */
  /* Double_t analyticalIntegral(Int_t code,const char* rangeName) const; */

private:

  ClassDef(RooHSSphHarMoments,1) // Your description goes here...
};
 
#endif

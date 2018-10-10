////////////////////////////////////////////////////////////////
///
///Class:               FiledTree
///Description:
///            A tree connected to its own TFile !
///            An attempt to stop file directory related crashes!
///            Note in interactive root session must create a new
///            object so we can call delete. If you let ROOT delete
///            after .q the file will not be writeable!
 
#ifndef HS_FILEDTREE_h
#define HS_FILEDTREE_h


#include <TTree.h>
#include <TFile.h>
#include <TString.h>
#include <iostream>

namespace HS{
  
  class FiledTree  {

  public:
    //////////////////////////////////////////////////////////////////////
    ///Construct a new tree to be branched and filled
    FiledTree(TString tname,TString fname,TString opt="recreate"){
      fFile.reset(TFile::Open(fname,opt));
      fTree.reset(new TTree(tname,"A FiledTree"));
      SetTreeDirectory();
    }
    //////////////////////////////////////////////////////////////////////
    ///Construct a tree based on an existing one
    ///if isfull is true copy all the events, if false just create empty tree
    FiledTree(Bool_t isfull,TTree *tree,TString fname,TString opt="recreate"){
      fFile.reset(TFile::Open(fname,opt));
      if(isfull)fTree.reset(tree->CloneTree(-1,"fast"));
      else fTree.reset(tree->CloneTree(0));
      SetTreeDirectory();
    }
    FiledTree(){};
    
    virtual ~FiledTree(){
      if(fFile){ 
	fFile->cd();
	if(fFile->IsWritable())
	  Tree()->Write();
	else{
	  std::cout<<"Warning deleting FiledTree but can't write to file!"<<endl;
	  std::cout<<"        this may mean you are letting ROOT cleanup "<<endl;
	  std::cout<<"        this object (i.e. after .q) rather than calling"<<endl;
	  std::cout<<"        its destructor somewhere in your code..."<<endl;
	  
	}	
      }
    }
    
    TTree* Tree() {return fTree.get();}
    void Fill(){Tree()->Fill();}

  protected :

    TFile* File(){return fFile.get();}
    void SetTreeDirectory(){ Tree()->SetDirectory(File());}
    
  private:
    std::unique_ptr<TFile> fFile;//file before tree as is owner
    std::unique_ptr<TTree> fTree;
  };
}//namespace HS
#endif


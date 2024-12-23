/******************************************************************************/
/* File   : aapFunctionalCluster_Persistency.cpp                              */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "TypesStd.hpp"

#include "interface_Persistency.hpp"
#include "interface_Persistency_FileStorage.hpp"
#include "interface_Persistency_ReadAccessor.hpp"
#include "interface_Persistency_ReadWriteAccessor.hpp"
#include "interface_Persistency_KeyValueStorage.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class aapFunctionalCluster_Persistency:
      public interface_Persistency
   ,  public interface_Persistency_FileStorage
   ,  public interface_Persistency_ReadAccessor
   ,  public interface_Persistency_ReadWriteAccessor
   ,  public interface_Persistency_KeyValueStorage
{
   public:
      void vGetCfg(
            uint64*     lpau64Cfg
         ,  std::string lps8File
      );

      void              GetCurrentFileStorageSize             (void);
      FileStorage       OpenFileStorage                       (void);
      void              RecoverAllFiles                       (void);
      void              ResetAllFiles                         (void);
      void              RegisterRecoveryReportCallback        (void);
      void              CleanUpPersistency                    (void);
      void              RegisterApplicationDataUpdateCallback (void);
      void              ResetPersistency                      (void);
      void              UpdatePersistency                     (void);
      void              DeleteFile                            (void);
      void              FileExists                            (void);
      void              GetAllFileNames                       (void);
      void              GetCurrentFileSize                    (void);
      void              GetFileInfo                           (void);
      ReadAccessor      OpenFileReadOnly                      (void);
      ReadWriteAccessor OpenFileReadWrite                     (void);
      ReadWriteAccessor OpenFileWriteOnly                     (void);
      void              RecoverFile                           (void);
      void              ResetFile                             (void);
      void              GetByte                               (void);
      void              GetChar                               (void);
      void              GetPosition                           (void);
      void              GetSize                               (void);
      void              IsEof                                 (void);
      void              MovePosition                          (void);
      void              PeekByte                              (void);
      void              PeekChar                              (void);
      void              ReadBinary                            (void);
      void              ReadLine                              (void);
      void              ReadText                              (void);
      void              SetPosition                           (void);
/*
      void              operator<<                            (void);
*/
      void              SetFileSize                           (void);
      void              SyncToFile                            (void);
      void              WriteBinary                           (void);
      void              WriteText                             (void);
      void              GetCurrentKeyValueStorageSize         (void);
      KeyValueStorage   OpenKeyValueStorage                   (void);
      void              RecoverKeyValueStorage                (void);
      void              ResetKeyValueStorage                  (void);
      void              DiscardPendingChanges                 (void);
      void              GetAllKeys                            (void);
      void              GetValue                              (void);
      void              KeyExists                             (void);
      void              RecoverKey                            (void);
      void              RemoveAllKeys                         (void);
      void              RemoveKey                             (void);
      void              ResetKey                              (void);
      void              SetValue                              (void);
      void              SyncToStorage                         (void);
};

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
aapFunctionalCluster_Persistency Persistency;
interface_Persistency* pPersistency = &Persistency;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cstdint>

void aapFunctionalCluster_Persistency::vGetCfg(
      uint64*     lpau64Cfg
   ,  std::string lps8File
){
   std::ifstream file(lps8File);
   if(!file){
      std::cerr << "ERROR: Failed to open the file." << std::endl;
   }
   else{
      std::stringstream buffer;
      buffer << file.rdbuf();
      std::string hexContent = buffer.str();

      std::istringstream ss(hexContent); //TBD: Optimize

      std::string line;
      uint16 u16CountData = 0;

      while(std::getline(ss, line)){
         if(
               10   < line.size()
            && ':' == line[0]
         ){
            std::istringstream lineStream_byteCount(line.substr(1, 2));
            int byteCount;
            lineStream_byteCount >> std::hex >> byteCount;

            if(2 != byteCount){
               uint16 u16Address;
               std::istringstream lineStream_u16Address(line.substr(3, 4));
               lineStream_u16Address >> std::hex >> u16Address;

               std::istringstream lineStream_recordType(line.substr(7, 2));
               int recordType;
               lineStream_recordType >> std::hex >> recordType;

               if(0 == recordType){
                  std::istringstream lineStream_u64Data(line.substr(9, 16));
                  lineStream_u64Data >> std::hex >> lpau64Cfg[u16CountData++];
               }
            }
         }
      }
   }
}

void aapFunctionalCluster_Persistency::GetCurrentFileStorageSize(void){
}

FileStorage aapFunctionalCluster_Persistency::OpenFileStorage(void){
   return 0;
}

void aapFunctionalCluster_Persistency::RecoverAllFiles(void){
}

void aapFunctionalCluster_Persistency::ResetAllFiles(void){
}

void aapFunctionalCluster_Persistency::RegisterRecoveryReportCallback (void){
}

void aapFunctionalCluster_Persistency::CleanUpPersistency(void){
}

void aapFunctionalCluster_Persistency::RegisterApplicationDataUpdateCallback(void){
}

void aapFunctionalCluster_Persistency::ResetPersistency(void){
}

void aapFunctionalCluster_Persistency::UpdatePersistency(void){
}

void aapFunctionalCluster_Persistency::DeleteFile(void){
}

void aapFunctionalCluster_Persistency::FileExists(void){
}

void aapFunctionalCluster_Persistency::GetAllFileNames(void){
}

void aapFunctionalCluster_Persistency::GetCurrentFileSize(void){
}

void aapFunctionalCluster_Persistency::GetFileInfo(void){
}

ReadAccessor aapFunctionalCluster_Persistency::OpenFileReadOnly(void){
   return 0;
}

ReadWriteAccessor aapFunctionalCluster_Persistency::OpenFileReadWrite(void){
   return 0;
}

ReadWriteAccessor aapFunctionalCluster_Persistency::OpenFileWriteOnly(void){
   return 0;
}

void aapFunctionalCluster_Persistency::RecoverFile(void){
}

void aapFunctionalCluster_Persistency::ResetFile(void){
}

void aapFunctionalCluster_Persistency::GetByte(void){
}

void aapFunctionalCluster_Persistency::GetChar(void){
}

void aapFunctionalCluster_Persistency::GetPosition(void){
}

void aapFunctionalCluster_Persistency::GetSize(void){
}

void aapFunctionalCluster_Persistency::IsEof(void){
}

void aapFunctionalCluster_Persistency::MovePosition(void){
}

void aapFunctionalCluster_Persistency::PeekByte(void){
}

void aapFunctionalCluster_Persistency::PeekChar(void){
}

void aapFunctionalCluster_Persistency::ReadBinary(void){
}

void aapFunctionalCluster_Persistency::ReadLine(void){
}

void aapFunctionalCluster_Persistency::ReadText(void){
}

void aapFunctionalCluster_Persistency::SetPosition(void){
}

/*
void aapFunctionalCluster_Persistency::operator<<(void){
}
*/

void aapFunctionalCluster_Persistency::SetFileSize(void){
}

void aapFunctionalCluster_Persistency::SyncToFile(void){
}

void aapFunctionalCluster_Persistency::WriteBinary(void){
}

void aapFunctionalCluster_Persistency::WriteText(void){
}

void aapFunctionalCluster_Persistency::GetCurrentKeyValueStorageSize(void){
}

KeyValueStorage aapFunctionalCluster_Persistency::OpenKeyValueStorage(void){
   return 0;
}

void aapFunctionalCluster_Persistency::RecoverKeyValueStorage(void){
}

void aapFunctionalCluster_Persistency::ResetKeyValueStorage(void){
}

void aapFunctionalCluster_Persistency::DiscardPendingChanges(void){
}

void aapFunctionalCluster_Persistency::GetAllKeys(void){
}

void aapFunctionalCluster_Persistency::GetValue(void){
}

void aapFunctionalCluster_Persistency::KeyExists(void){
}

void aapFunctionalCluster_Persistency::RecoverKey(void){
}

void aapFunctionalCluster_Persistency::RemoveAllKeys(void){
}

void aapFunctionalCluster_Persistency::RemoveKey(void){
}

void aapFunctionalCluster_Persistency::ResetKey(void){
}

void aapFunctionalCluster_Persistency::SetValue(void){
}

void aapFunctionalCluster_Persistency::SyncToStorage(void){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

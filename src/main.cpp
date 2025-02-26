#include <RED4ext/RED4ext.hpp>
// You must include RedLib. Note that it introduces an alias
// such as namespace RED4ext can be replaced by Red.
#include <RedLib.hpp>

RED4EXT_C_EXPORT bool RED4EXT_CALL Main(RED4ext::PluginHandle aHandle,
                                        RED4ext::EMainReason aReason,
                                        const RED4ext::Sdk* aSdk) {
  switch (aReason)  {
  case RED4ext::EMainReason::Load: {
    // It will automatically register types declared below.
    Red::TypeInfoRegistrar::RegisterDiscovered();
    break;
  }
  case RED4ext::EMainReason::Unload: {
    break;
  }
  }
  return true;
}

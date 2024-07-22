#pragma once

enum RwRenderState : int32_t
{
  rwRENDERSTATENARENDERSTATE = 0x0,
  rwRENDERSTATETEXTURERASTER = 0x1,
  rwRENDERSTATETEXTUREADDRESS = 0x2,
  rwRENDERSTATETEXTUREADDRESSU = 0x3,
  rwRENDERSTATETEXTUREADDRESSV = 0x4,
  rwRENDERSTATETEXTUREPERSPECTIVE = 0x5,
  rwRENDERSTATEZTESTENABLE = 0x6,
  rwRENDERSTATESHADEMODE = 0x7,
  rwRENDERSTATEZWRITEENABLE = 0x8,
  rwRENDERSTATETEXTUREFILTER = 0x9,
  rwRENDERSTATESRCBLEND = 0xA,
  rwRENDERSTATEDESTBLEND = 0xB,
  rwRENDERSTATEVERTEXALPHAENABLE = 0xC,
  rwRENDERSTATEBORDERCOLOR = 0xD,
  rwRENDERSTATEFOGENABLE = 0xE,
  rwRENDERSTATEFOGCOLOR = 0xF,
  rwRENDERSTATEFOGTYPE = 0x10,
  rwRENDERSTATEFOGDENSITY = 0x11,
  rwRENDERSTATECULLMODE = 0x14,
  rwRENDERSTATESTENCILENABLE = 0x15,
  rwRENDERSTATESTENCILFAIL = 0x16,
  rwRENDERSTATESTENCILZFAIL = 0x17,
  rwRENDERSTATESTENCILPASS = 0x18,
  rwRENDERSTATESTENCILFUNCTION = 0x19,
  rwRENDERSTATESTENCILFUNCTIONREF = 0x1A,
  rwRENDERSTATESTENCILFUNCTIONMASK = 0x1B,
  rwRENDERSTATESTENCILFUNCTIONWRITEMASK = 0x1C,
  rwRENDERSTATEALPHATESTFUNCTION = 0x1D,
  rwRENDERSTATEALPHATESTFUNCTIONREF = 0x1E,
  rwRENDERSTATEFORCEENUMSIZEINT = 0x7FFFFFFF,
};

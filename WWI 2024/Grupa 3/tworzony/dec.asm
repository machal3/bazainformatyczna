                             *************************************************************
                             *                           FUNCTION                          
                             *************************************************************
                             int  __cdecl  _main (int  _Argc , char * *  _Argv , char * *  _
             int               EAX:4          <RETURN>
             int               Stack[0x4]:4   _Argc                                   XREF[1]:     00401460 (*)   
             char * *          Stack[0x8]:4   _Argv
             char * *          Stack[0xc]:4   _Env
             undefined4        Stack[0x0]:4   local_res0                              XREF[2]:     00401467 (R) , 
                                                                                                   004014fa (*)   
             undefined4        Stack[-0xc]:4  local_c                                 XREF[1]:     004014f6 (R)   
             undefined4        Stack[-0x14]:4 local_14                                XREF[7]:     004014a1 (W) , 
                                                                                                   004014a4 (R) , 
                                                                                                   004014b5 (W) , 
                                                                                                   004014b8 (R) , 
                                                                                                   004014be (R) , 
                                                                                                   004014d3 (R) , 
                                                                                                   004014de (R)   
             undefined4        Stack[-0x18]:4 local_18                                XREF[2]:     00401476 (*) , 
                                                                                                   00401489 (R)   
             undefined4        Stack[-0x30]:4 local_30                                XREF[3]:     00401479 (*) , 
                                                                                                   004014c1 (*) , 
                                                                                                   004014e1 (*)   
                             .text                                           XREF[1]:     FUN_004011b0:00401283 (c)   
                             _main
        00401460 8d  4c  24  04    LEA        ECX =>_Argc ,[ESP  + 0x4 ]
        00401464 83  e4  f0       AND        ESP ,0xfffffff0
        00401467 ff  71  fc       PUSH       dword ptr [ECX  + local_res0 ]
        0040146a 55              PUSH       EBP
        0040146b 89  e5           MOV        EBP ,ESP
        0040146d 51              PUSH       ECX
        0040146e 83  ec  24       SUB        ESP ,0x24
        00401471 e8  3a  06       CALL       ___main                                          undefined ___main(void)
                 00  00
        00401476 8d  45  f0       LEA        EAX =>local_18 ,[EBP  + -0x10 ]
        00401479 89  04  24       MOV        dword ptr [ESP ]=>local_30 ,EAX
                             __fu0___ZSt3cin (0040147c+1)                    XREF[0,6]:   __pei386_runtime_relocator:00401
                                                                                          __pei386_runtime_relocator:00402
                                                                                          __pei386_runtime_relocator:00402
                                                                                          __pei386_runtime_relocator:00402
                                                                                          __pei386_runtime_relocator:00402
                                                                                          __pei386_runtime_relocator:00402
        0040147c b9  00  00       MOV        ECX ,_ZSt3cin                                    = ??
                 00  10
        00401481 e8  ee  00       CALL       std::basic_istream<>::operator>>                 undefined operator>>(basic_istre
                 00  00
        00401486 83  ec  04       SUB        ESP ,0x4
        00401489 8b  4d  f0       MOV        ECX ,dword ptr [EBP  + local_18 ]
        0040148c ba  67  66       MOV        EDX ,0x66666667
                 66  66
        00401491 89  c8           MOV        EAX ,ECX
        00401493 f7  ea           IMUL       EDX
        00401495 c1  fa  03       SAR        EDX ,0x3
        00401498 89  c8           MOV        EAX ,ECX
        0040149a c1  f8  1f       SAR        EAX ,0x1f
        0040149d 29  c2           SUB        EDX ,EAX
        0040149f 89  d0           MOV        EAX ,EDX
        004014a1 89  45  f4       MOV        dword ptr [EBP  + local_14 ],EAX
        004014a4 8b  55  f4       MOV        EDX ,dword ptr [EBP  + local_14 ]
        004014a7 89  d0           MOV        EAX ,EDX
        004014a9 c1  e0  02       SHL        EAX ,0x2
        004014ac 01  d0           ADD        EAX ,EDX
        004014ae c1  e0  02       SHL        EAX ,0x2
        004014b1 29  c1           SUB        ECX ,EAX
        004014b3 89  c8           MOV        EAX ,ECX
        004014b5 89  45  f4       MOV        dword ptr [EBP  + local_14 ],EAX
        004014b8 83  7d  f4  0a    CMP        dword ptr [EBP  + local_14 ],0xa
        004014bc 7f  15           JG         LAB_004014d3
        004014be 8b  45  f4       MOV        EAX ,dword ptr [EBP  + local_14 ]
        004014c1 89  04  24       MOV        dword ptr [ESP ]=>local_30 ,EAX
                             __fu1___ZSt4cout (004014c4+1)
        004014c4 b9  04  00       MOV        ECX ,_ZSt4cout                                   = ??
                 00  10
        004014c9 e8  9e  00       CALL       std::basic_ostream<>::operator<<                 undefined operator<<(basic_ostre
                 00  00
        004014ce 83  ec  04       SUB        ESP ,0x4
        004014d1 eb  1e           JMP        LAB_004014f1
                             LAB_004014d3                                    XREF[1]:     004014bc (j)   
        004014d3 83  7d  f4  0a    CMP        dword ptr [EBP  + local_14 ],0xa
        004014d7 7e  18           JLE        LAB_004014f1
        004014d9 b8  14  00       MOV        EAX ,0x14
                 00  00
        004014de 2b  45  f4       SUB        EAX ,dword ptr [EBP  + local_14 ]
        004014e1 89  04  24       MOV        dword ptr [ESP ]=>local_30 ,EAX
                             __fu2___ZSt4cout (004014e4+1)
        004014e4 b9  04  00       MOV        ECX ,_ZSt4cout                                   = ??
                 00  10
        004014e9 e8  7e  00       CALL       std::basic_ostream<>::operator<<                 undefined operator<<(basic_ostre
                 00  00
        004014ee 83  ec  04       SUB        ESP ,0x4
                             LAB_004014f1                                    XREF[2]:     004014d1 (j) , 004014d7 (j)   
        004014f1 b8  00  00       MOV        EAX ,0x0
                 00  00
        004014f6 8b  4d  fc       MOV        ECX ,dword ptr [EBP  + local_c ]
        004014f9 c9              LEAVE
        004014fa 8d  61  fc       LEA        ESP =>local_res0 ,[ECX  + -0x4 ]
        004014fd c3              RET

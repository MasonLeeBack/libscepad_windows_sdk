@echo off

REM Script inspired by http://stackoverflow.com/questions/9946322/how-to-generate-an-import-library-lib-file-from-a-dll

if not exist libScePad.dll (
	echo Make sure libScePad.dll is in this directory!
	goto end
)

bin\dumpbin /exports libScePad.dll > libScePad-exports.txt

echo LIBRARY libScePad > libScePad.def
echo EXPORTS >> libScePad.def
for /f "skip=19 tokens=1,4" %%A in (libScePad-exports.txt) do if NOT "%%B" == "" (echo %%B @%%A >> libScePad.def)

bin\lib /def:libScePad.def /out:libScePad.lib /machine:x64

REM Clean up temporary intermediate files
del libScePad-exports.txt libScePad.def libScePad.exp

:end
@echo on
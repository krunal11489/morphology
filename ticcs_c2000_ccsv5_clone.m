% NOTE: DO NOT REMOVE THIS LINE XMAKEFILE_TOOL_CHAIN_CONFIGURATION
function toolChainConfiguration = ticcs_c2000_ccsv5_clone()
%TICCS_C2000_CCSV5_CLONE Defines a tool chain configuration.
%
% Copyright 2015 The MathWorks, Inc.
%
% General
toolChainConfiguration.Configuration   = 'ticcs_c2000_ccsv5_clone';
toolChainConfiguration.Version         = '2.0';
toolChainConfiguration.Description     = 'TI CCS v5 C2000 Tool Chain Configuration';
toolChainConfiguration.Operational     = true;
toolChainConfiguration.InstallPath     = '';
toolChainConfiguration.Decorator       = 'linkfoundation.xmakefile.decorator.c2000CCEv5Decorator';
% Make
toolChainConfiguration.MakePath        = 'C:\Program Files\MATLAB\R2012b\bin\win64\gmake';
toolChainConfiguration.MakeFlags       = '-f "[|||MW_XMK_GENERATED_FILE_NAME[R]|||]" [|||MW_XMK_ACTIVE_BUILD_ACTION_REF|||]';
toolChainConfiguration.MakeInclude     = '';
% Compiler
toolChainConfiguration.CompilerPath     = 'bin/cl2000';
toolChainConfiguration.CompilerFlags    = '-I"include" -fr"[|||MW_XMK_DERIVED_PATH_REF|||]"';
toolChainConfiguration.SourceExtensions = '.c,.asm,.abs,.sa';
toolChainConfiguration.HeaderExtensions = '.h';
toolChainConfiguration.ObjectExtension  = '.obj';
% Linker
toolChainConfiguration.LinkerPath        = 'bin/cl2000';
toolChainConfiguration.LinkerFlags       = '-o [|||MW_XMK_GENERATED_TARGET_REF|||]';
toolChainConfiguration.LibraryExtensions = '.lib,.cmd';
toolChainConfiguration.TargetExtension   = '.out';
toolChainConfiguration.TargetNamePrefix  = '';
toolChainConfiguration.TargetNamePostfix = '';
% Archiver
toolChainConfiguration.ArchiverPath      = 'bin/ar2000';
toolChainConfiguration.ArchiverFlags     = '-r [|||MW_XMK_GENERATED_TARGET_REF|||]';
toolChainConfiguration.ArchiveExtension  = '.lib';
toolChainConfiguration.ArchiveNamePrefix = '';
toolChainConfiguration.ArchiveNamePostfix= '';
% Pre-build
toolChainConfiguration.PrebuildEnable   = false;
toolChainConfiguration.PrebuildToolPath = '';
toolChainConfiguration.PrebuildFlags    = '';
% Post-build
toolChainConfiguration.PostbuildEnable   = false;
toolChainConfiguration.PostbuildToolPath = '';
toolChainConfiguration.PostbuildFlags    = '';
% Execute
toolChainConfiguration.ExecuteDefault  = false;
toolChainConfiguration.ExecuteToolPath = 'echo';
toolChainConfiguration.ExecuteFlags    = 'To customize the execute command, clone this configuration';
% Directories
toolChainConfiguration.DerivedPath     = '';
toolChainConfiguration.OutputPath      = '';
% Custom
toolChainConfiguration.Custom1         = '';
toolChainConfiguration.Custom2         = '';
toolChainConfiguration.Custom3         = '';
toolChainConfiguration.Custom4         = '';
toolChainConfiguration.Custom5         = '';
end

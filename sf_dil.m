function sf_dil(block)
%MSFUNTMPL_BASIC A Template for a Level-2 MATLAB S-Function
%   The MATLAB S-function is written as a MATLAB function with the
%   same name as the S-function. Replace 'msfuntmpl_basic' with the 
%   name of your S-function.
%
%   It should be noted that the MATLAB S-function is very similar
%   to Level-2 C-Mex S-functions. You should be able to get more
%   information for each of the block methods by referring to the
%   documentation for C-Mex S-functions.
%
%   Copyright 2003-2010 The MathWorks, Inc.

%%
%% The setup method is used to set up the basic attributes of the
%% S-function such as ports, parameters, etc. Do not add any other
%% calls to the main body of the function.
%%
setup(block);

%endfunction

%% Function: setup ===================================================
%% Abstract:
%%   Set up the basic characteristics of the S-function block such as:
%%   - Input ports
%%   - Output ports
%%   - Dialog parameters
%%   - Options
%%
%%   Required         : Yes
%%   C-Mex counterpart: mdlInitializeSizes
%%
function setup(block)

% Register number of ports
block.NumInputPorts  = 1;
block.NumOutputPorts = 1;

% Setup port properties to be inherited or dynamic
block.SetPreCompInpPortInfoToDynamic;
block.SetPreCompOutPortInfoToDynamic;

% Override input port properties
% block.InputPort(1).Dimensions        = 1;
% block.InputPort(1).DatatypeID  = 0;  % double
% block.InputPort(1).Complexity  = 'Real';
% block.InputPort(1).DirectFeedthrough = true;
% 
% % Override output port properties
% block.OutputPort(1).Dimensions       = 1;
% block.OutputPort(1).DatatypeID  = 0; % double
% block.OutputPort(1).Complexity  = 'Real';

% Register parameters
block.NumDialogPrms     = 1;
block.DialogPrmsTunable = {'Nontunable'};

% Register sample times
%  [0 offset]            : Continuous sample time
%  [positive_num offset] : Discrete sample time
%
%  [-1, 0]               : Inherited sample time
%  [-2, 0]               : Variable sample time
block.SampleTimes = [-1 0];

% Specify the block simStateCompliance. The allowed values are:
%    'UnknownSimState', < The default setting; warn and assume DefaultSimState
%    'DefaultSimState', < Same sim state as a built-in block
%    'HasNoSimState',   < No sim state
%    'CustomSimState',  < Has GetSimState and SetSimState methods
%    'DisallowSimState' < Error out when saving or restoring the model sim state
block.SimStateCompliance = 'DefaultSimState';

%% -----------------------------------------------------------------
%% The MATLAB S-function uses an internal registry for all
%% block methods. You should register all relevant methods
%% (optional and required) as illustrated below. You may choose
%% any suitable name for the methods and implement these methods
%% as local functions within the same file. See comments
%% provided for each function for more information.
%% -----------------------------------------------------------------
block.RegBlockMethod('CheckParameters', @CheckPrms);
% block.RegBlockMethod('PostPropagationSetup',    @DoPostPropSetup);
% block.RegBlockMethod('InitializeConditions', @InitializeConditions);
% block.RegBlockMethod('Start', @Start);
block.RegBlockMethod('Outputs', @Outputs);     % Required
% block.RegBlockMethod('Update', @Update);
% block.RegBlockMethod('Derivatives', @Derivatives);
% block.RegBlockMethod('Terminate', @Terminate); % Required

%end setup
function CheckPrms(block)
  
  a = block.DialogPrm(1).Data;
  [kp1,kp2]=size(a);
  t1=mod(kp1,2);t2=mod(kp2,2);
  if ((t1==0 && t2==0))
    me = MSLException(block.BlockHandle, message('Simulink:blocks:invalidParameter'));
    throw(me);
  end

%%
%% PostPropagationSetup:
%%   Functionality    : Setup work areas and state variables. Can
%%                      also register run-time methods here
%%   Required         : No
%%   C-Mex counterpart: mdlSetWorkWidths
%%
% function DoPostPropSetup(block)
% block.NumDworks = 1;
%   
%   block.Dwork(1).Name            = 'x1';
%   block.Dwork(1).Dimensions      = 1;
%   block.Dwork(1).DatatypeID      = 0;      % double
%   block.Dwork(1).Complexity      = 'Real'; % real
%   block.Dwork(1).UsedAsDiscState = true;


%%
%% InitializeConditions:
%%   Functionality    : Called at the start of simulation and if it is 
%%                      present in an enabled subsystem configured to reset 
%%                      states, it will be called when the enabled subsystem
%%                      restarts execution to reset the states.
%%   Required         : No
%%   C-MEX counterpart: mdlInitializeConditions
%%
% function InitializeConditions(block)
% 
% %end InitializeConditions


%%
%% Start:
%%   Functionality    : Called once at start of model execution. If you
%%                      have states that should be initialized once, this 
%%                      is the place to do it.
%%   Required         : No
%%   C-MEX counterpart: mdlStart
%%
% function Start(block)
% 
% block.Dwork(1).Data = 0;
% 
% %endfunction
%%
%%
%% Outputs:
%%   Functionality    : Called to generate block outputs in
%%                      simulation step
%%   Required         : Yes
%%   C-MEX counterpart: mdlOutputs
%%

function [I1]=dil_m(I,se)

%I = imread('text_gaps.tif');
%I(445:508,1:508)=false;
%I=true(10,10);
%figure,imshow(I);
[m,n]=size(I);
I1=false(m,n);
%se=true(3,3);
se=rflctn(se);
[sm,sn]=size(se);
p=fix(sm/2);
r=fix(sn/2);
J(1:m+2*p,1:n+2*r)=false;
for i=1:m;
    for j=1:n;
        %if(i>p && i<m+p+1)
            %if(j>p && j<m+p+1)
                J(i+p,j+r)=I(i,j);
            %end 
        %end
    end
end
%figure,imshow(J);
for i=p+1:m+p;
    for j=r+1:n+r;
        q=1;
        q1=J(i-p:i+p,j-r:j+r).*se;
        if(se==1)
            if(q1==0)
                q=0;
            end
        else
            q=0;
            for si=1:2*p+1;
                for sj=1:2*r+1;
                    if(se(si,sj)==true)
                        if(q1(si,sj)==true)
                            q=1;break;
                        end
                    end
                end
                if(q==1)
                   break;
                end
            end     
        end
        if(q==0)
           I1(i-p,j-r)=false;
        else
           I1(i-p,j-r)=true;
        end
    end
end

function Outputs(block)
  I=block.InputPort(1).Data;
  se= block.DialogPrm(1).Data;

  block.OutputPort(1).Data =dil_m(I,se);  

%end Outputs

%%
%% Update:
%%   Functionality    : Called to update discrete states
%%                      during simulation step
%%   Required         : No
%%   C-MEX counterpart: mdlUpdate
%%
% function Update(block)
% 
% block.Dwork(1).Data = block.InputPort(1).Data;

%end Update

%%
%% Derivatives:
%%   Functionality    : Called to update derivatives of
%%                      continuous states during simulation step
%%   Required         : No
%%   C-MEX counterpart: mdlDerivatives
%%
% function Derivatives(block)
% 
% %end Derivatives

%%
%% Terminate:
%%   Functionality    : Called at the end of simulation for cleanup
%%   Required         : Yes
%%   C-MEX counterpart: mdlTerminate
%%
% function Terminate(block)

%end Terminate


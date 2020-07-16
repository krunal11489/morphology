function Hd = fdatest
%FDATEST Returns a discrete-time filter object.

%
% M-File generated by MATLAB(R) 7.5 and the Signal Processing Toolbox 6.8.
%
% Generated on: 02-Feb-2012 20:14:36
%

% Equiripple Bandpass filter designed using the FIRPM function.

% All frequency values are in Hz.
Fs = 2000;  % Sampling Frequency

Fstop1 = 200;              % First Stopband Frequency
Fpass1 = 300;              % First Passband Frequency
Fpass2 = 700;              % Second Passband Frequency
Fstop2 = 800;              % Second Stopband Frequency
Dstop1 = 0.000177827941;   % First Stopband Attenuation
Dpass  = 0.0057563991496;  % Passband Ripple
Dstop2 = 0.000177827941;   % Second Stopband Attenuation
dens   = 16;               % Density Factor

% Calculate the order from the parameters using FIRPMORD.
[N, Fo, Ao, W] = firpmord([Fstop1 Fpass1 Fpass2 Fstop2]/(Fs/2), [0 1 ...
                          0], [Dstop1 Dpass Dstop2]);

% Calculate the coefficients using the FIRPM function.
b  = firpm(N, Fo, Ao, W, {dens});
Hd = dfilt.dffir(b);

% [EOF]

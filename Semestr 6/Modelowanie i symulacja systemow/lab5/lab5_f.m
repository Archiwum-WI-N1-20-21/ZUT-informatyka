close all;
clear;

out = sim("lab5.slx");

h1 = out.h1;
h2 = out.h2;
h1max = max(h1) + 1;
h2max = max(h2) + 1;

S1 = str2num(get_param("lab5/Subsystem", "S1"));
S2 = str2num(get_param("lab5/Subsystem", "S2"));
Swy1 = str2num(get_param("lab5/Subsystem", "Swy1"));
Swy2 = str2num(get_param("lab5/Subsystem", "Swy2"));

t = 2^-5;

for i = 1:length(h1)
    hold on
    plot([0,S1+S2+2],[0,0]);
    plot([S1,S1+1],[Swy1,Swy1]);
    plot([S1+1,S1+1],[Swy1,h2max]);
    plot([S1+S2+1,S1+S2+1],[Swy2,h2max]);
    plot([S1+S2+1,S1+S2+2],[Swy2,Swy2]);
    %plot([2,S1+S2+2],[2,0]);
    %plot([3,S1+S2+2],[3,0]);
    fill([0,S1,S1,0],[0,0,h1(i),h1(i)],'blue',EdgeColor = 'none')
    fill([S1,S1+1,S1+1,S1],[0,0,Swy1,Swy1],'blue',EdgeColor = 'none')
    fill([S1+1,S1+S2+1,S1+S2+1,S1+1],[0,0,h2(i),h2(i)],'blue',EdgeColor = 'none')
    fill([S1+S2+1,S1+S2+2,S1+S2+2,S1+S2+1],[0,0,Swy2,Swy2],'blue',EdgeColor = 'none')
    hold off
    pause(t);
end
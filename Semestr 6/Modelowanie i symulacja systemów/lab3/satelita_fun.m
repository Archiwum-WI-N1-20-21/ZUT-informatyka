close all;
clear;

out = sim("model_satelita.slx");
x = out.x;
y = out.y;

r = str2num(get_param("model_satelita/Subsystem", "r"));
rs = str2num(get_param("model_satelita/Subsystem", "rs"));

t = 2^(-7);

for i = 1:length(x)
    plot(x(1:i), y(1:i));
    hold on

    rectangle('position', [0-r, 0-r, 2*r, 2*r], 'curvature', [1,1]);
    rectangle('position', [x(i)-rs, y(i)-rs, 2*rs, 2*rs], 'curvature', [1,1]);
    hold off

    axis([-8, 8, -8, 8]);
    daspect([1, 1, 1]);
    pause(t);
end
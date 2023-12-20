const std = @import("std");

pub fn main() !void {
    const file = @embedFile("text.txt");

    const returnP1 = try part1(file);

    std.debug.print("{d}", .{returnP1});
}

fn part1(input: []const u8) !usize {
    const maxCubes = [3]u4{ 12, 13, 14 };
    const numbers = @Vector(10, i32);
    _ = numbers;
    var result: usize = 0;
    var lines = std.mem.tokenizeScalar(u8, input, '\n');

    while (lines.next()) |line| {
        var gameInput = std.mem.splitScalar(u8, line, ':');
        var gameString = gameInput.next().?;
        var gameName = std.mem.splitScalar(u8, gameString, ' ');
        var gameNameString = gameName.next().?;
        _ = gameNameString;
        var gameIdString = gameName.next().?;
        var gameId = try std.fmt.parseInt(usize, gameIdString, 10);
        var hands = gameInput.next().?;
        var hand = std.mem.splitScalar(u8, hands, ';');
        var impossible: bool = false;
        while (hand.next()) |x| {
            var cubes = std.mem.splitScalar(u8, x, ',');
            while (cubes.next()) |y| {
                var segment = std.mem.tokenizeScalar(u8, y, ' ');
                const numberString = segment.next().?;
                const colorString = segment.next().?;
                const numberValue = try std.fmt.parseInt(usize, numberString, 10);

                if (std.mem.eql(u8, colorString, "red") and numberValue > maxCubes[0]) {
                    impossible = true;
                } else if (std.mem.eql(u8, colorString, "green") and numberValue > maxCubes[1]) {
                    impossible = true;
                } else if (std.mem.eql(u8, colorString, "blue") and numberValue > maxCubes[2]) {
                    impossible = true;
                }
            }
        }
        if (!impossible) {
            result += gameId;
        }
    }
    return result;
}

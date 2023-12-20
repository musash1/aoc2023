const std = @import("std");

pub fn main() !void {
    const file = @embedFile("test.txt");

    const returnP1 = try part1(file);

    std.debug.print("{d}", .{returnP1});
}

fn part1(input: []const u8) !usize {
    const maxCubes = [3]u4{ 12, 13, 14 };
    _ = maxCubes;
    const numbers = @Vector(10, i32);
    _ = numbers;
    var result: usize = 0;
    _ = result;
    var lines = std.mem.tokenizeScalar(u8, input, '\n');

    while (lines.next()) |line| {
        var gameInput = std.mem.splitScalar(u8, line, ':');
        var gameIdString = gameInput.next().?;
        _ = gameIdString;
        var hands = gameInput.next().?;
        var singeGames = std.mem.tokenizeScalar(u8, hands, ';');
        std.debug.print("{s}", .{singeGames.next().?});
    }

    return 0;
}

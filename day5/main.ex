defmodule Day5 do
    def main do
        {:ok, contents} = File.read("test.txt") 
        part1(contents)
    end

    def part1(file) do
        lines = String.split(file, "\n", trim: true)
        lines2 = Enum.filter(lines, fn x -> Regex.match?(~r/\d+/, x) == true end)
        IO.inspect lines2
    end
end

Day5.main()

defmodule Day5 do
    def main do
        {:ok, contents} = File.read("test.txt") 
        part1(contents)
    end

    def part1(file) do
        blocks = String.split(file, "\n\n", trim: true) 
        lines = Enum.map(blocks, fn x -> String.split(x, "\n", trim: true) end)
        IO.inspect lines
    end
end

Day5.main()

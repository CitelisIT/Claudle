import { Popover } from "@headlessui/react";
import { XIcon } from "@heroicons/react/outline";
import GameBoard from "./GameBoard";

interface Props {
  listWord: string[][];
  hints: number[][];
  target: string;
  togglePopup: (state: boolean) => void;
}

export default function HistoryPopup({
  listWord,
  hints,
  target,
  togglePopup,
}: Props) {
  return (
    <Popover>
      <Popover.Button className="hover:underline">Afficher</Popover.Button>
      <Popover.Panel className="fixed inset-0 w-10/12 m-auto text-gray-200 bg-gray-900 border border-gray-600 rounded-lg shadow-2xl h-fit">
        <div className="flex px-6 pt-6 items-center justify-between w-full > ">
          <div className="text-2xl">Mot cherché : {target.toUpperCase()} </div>
          <Popover.Button>
            <XIcon className="h-6 text-gray-200 md:w-8 md:h-8" />
          </Popover.Button>
        </div>

        <GameBoard words={listWord} hints={hints} />
      </Popover.Panel>
    </Popover>
  );
}

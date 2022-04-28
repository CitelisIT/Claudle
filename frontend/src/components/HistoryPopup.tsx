import { Dialog, Popover } from "@headlessui/react";
import GameBoard from "./GameBoard";

interface Props {
  listWord: string[][];
  hints: number[][];
  histoOpen: boolean;
  togglePopup: (state: boolean) => void;
}

export default function HistoryPopup({
  listWord,
  hints,
  histoOpen,
  togglePopup,
}: Props) {
  return (
    <Popover>
      <Popover.Button>voir la partie</Popover.Button>
      <Popover.Panel className="fixed inset-0 w-10/12 p-4 m-auto text-gray-200 bg-gray-900 border border-gray-600 rounded-lg shadow-2xl mg:p-8 lg:w-5/12 mx-1/2 h-fit">
        <GameBoard words={listWord} hints={hints} />
      </Popover.Panel>
    </Popover>
  );
}
